#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7
#define N 10005

int dfsc, rc, root, cc_num, dfs_parent[N], dfs_low[N], dfs_num[N], cc[N];
vector<vi> adj, bridge;

void getBridge(int u) { 
	dfs_low[u] = dfs_num[u] = dfsc++;
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (dfs_num[v] == -1) { 
			dfs_parent[v] = u;
			if (u == root) ++rc;
			getBridge(v);
			if (dfs_low[v] > dfs_num[u]) bridge[u].pb(v), bridge[v].pb(u);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
}

void connComp(int u) { 
	queue<int> q;
	q.push(u);
	while (!q.empty()) { 
		int v = q.front();
		q.pop();
		cc[v] = cc_num;
		f(i, 0, bridge[v].size(), 1) { 
			int w = bridge[v][i];
			if (!cc[w]) q.push(w);
		}
	}
	++cc_num;
}

int main() {
	int r, c, q, x, y;
    while (scanf("%d %d %d", &r, &c, &q)) {
		if (!r) break;
		reset(dfs_low, 0), reset(dfs_num, -1), reset(cc, 0), reset(dfs_parent, 0);
		adj.assign(r, {});
		bridge.assign(r, {});
		f(i, 0, c, 1) { 
			cin >> x >> y;
			adj[x - 1].pb(y - 1);
			adj[y - 1].pb(x - 1);
		}
		f(i, 0, r, 1) { 
			if (dfs_num[i] == -1) { 
				dfsc = 0, rc = 0, root = i;
				getBridge(i);
			}
		}
		cc_num = 1;
		f(i, 0, r, 1) if (!cc[i]) connComp(i);
		f(i, 0, q, 1) { 
			cin >> x >> y;
			if (cc[x - 1] == cc[y - 1]) cout << "Y\n";
			else cout << "N\n";
		}
		cout << "-\n";
	}
	return 0;
}
