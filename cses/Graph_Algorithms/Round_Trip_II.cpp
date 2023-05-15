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
 
vi c, p;
vvi adj;
int n, m, en, st;
 
bool dfs(int u) { 
	c[u] = 1;
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (c[v] == 0) { 
			p[v] = u;
			if (dfs(v)) return true;
		} else if (c[v] == 1) { 
			en = u, st = v;
			return true;
		}
	}
	c[u] = 2;
	return false;
}
 
int main() {
	cin >> n >> m;
	c.assign(n + 1, 0);
	p = c;
	adj.assign(n + 1, vi());
	int a, b;
	f(i, 0, m, 1) { 
		cin >> a >> b;
		adj[a].pb(b);
	}
	f(i, 1, n + 1, 1) { 
		if (!c[i] && dfs(i)) { 
			vi path;
			path.pb(st);
			for (int u = en; u != st; u = p[u]) path.pb(u);
			path.pb(st);
			reverse(all(path));
			cout << path.size() << nl;
			for (auto x : path) cout << x << " ";
			cout << nl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}