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
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1000000007
 
vi c, ts;
vvi adj;
int n, m;
 
bool dfs(int u) { 
	c[u] = 1;
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (c[v] == 0) { 
			if (dfs(v)) return true;
		} else if (c[v] == 1) { 
			return true;
		}
	}
	c[u] = 2;
	return false;
}
 
void dfs2(int u) { 
	c[u] = 1;
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (!c[v]) dfs2(v);
	}
	ts.pb(u);
}
 
int main() {
	cin >> n >> m;
	c.assign(n + 1, 0);
	adj.assign(n + 1, vi());
	int a, b;
	f(i, 0, m, 1) { 
		cin >> a >> b;
		adj[a].pb(b);
	}
	f(i, 1, n + 1, 1) { 
		if (!c[i] && dfs(i)) { 
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	c.assign(n + 1, 0);
	f(i, 1, n + 1, 1) if (!c[i]) dfs2(i);
	reverse(all(ts));
	f(i, 0, ts.size(), 1) cout << ts[i] << " ";
	cout << nl;
	return 0;
}