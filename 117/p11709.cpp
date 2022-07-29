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

vector<vi> adj; 
vi stk, vis, dfs_num, dfs_low;
vector<string> pr;
int cn, scc;
map<string, int> pr_idx;

void getSCC(int u) { 
	dfs_low[u] = dfs_num[u] = cn++;
	vis[u] = 1;
	stk.pb(u);
	f(i, 0, adj[u].size(), 1) { 
		int k = adj[u][i];
		if (dfs_num[k] == -1) getSCC(k);
		if (vis[k]) dfs_low[u] = min(dfs_low[u], dfs_low[k]);
	}
	if (dfs_low[u] == dfs_num[u]) { 
		++scc;
		while (1) { 
			int v = stk.back();
			stk.pop_back();
			vis[v] = 0;
			if (u == v) break;
		}
	}
}

int main() {
	int p, t, a, b;
	string s;
	while (cin >> p >> t && p) { 
		cin.ignore(1, '\n');
		adj.assign(p, {}); pr.assign(p, "");
		vis.assign(p, 0); dfs_num.assign(p, -1);
		dfs_low.assign(p, 0);
		cn = scc = 0;
		f(i, 0, p, 1) { 
			getline(cin, s);
			pr[i] = s;
			pr_idx[s] = i;
		}
		f(i, 0, t, 1) { 
			getline(cin, s);
			a = pr_idx[s];
			getline(cin, s);
			b = pr_idx[s];
			adj[a].pb(b);
		}
		f(i, 0, p, 1) if (dfs_num[i] == -1) getSCC(i);
		cout << scc << "\n";
	} 
	return 0;
}
