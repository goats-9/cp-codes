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
#define MOD (int)1e9 + 7

int ctr, cr;
vector<vi> adj;
vi path, vis;

void disp() { 
	int n = path.size();
	f(i, 0, n, 1) { 
		printf("%d", path[i]);
		if (i != n - 1) printf(" ");
		else printf("\n");
	}
}

void dfs(int u) { 
	if (u == cr) {disp(); ++ctr; return;}
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (!vis[v]) {
			vis[v] = 1;
			path.pb(v);
			dfs(v);
			vis[v] = 0;
			path.pop_back();
		}
	}
}

bool can_vis(int u) { 
	queue<int> q;
	q.push(u);
	while (!q.empty()) { 
		int v = q.front();
		vis[v] = 1;
		q.pop();
		f(i, 0, adj[v].size(), 1) { 
			int v1 = adj[v][i];
			if (!vis[v1]) q.push(v1);
		}
	}
	return vis[cr];
}

int main() {
	int x, y, tc = 0;
	while (cin >> cr) { 
		adj.assign(22, vi ());
		vis.assign(22, 0);
		path.clear();
		ctr = 0;
		while (cin >> x >> y && x) adj[x].pb(y), adj[y].pb(x);
		f(i, 0, adj.size(), 1) sort(adj[i].begin(), adj[i].end());
		printf("CASE %d:\n", ++tc);
		if (can_vis(1)) {
			vis.assign(22, 0);
			path.pb(1);
			vis[1] = 1;
			dfs(1);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n", ctr, cr);
	}
	return 0;
}
