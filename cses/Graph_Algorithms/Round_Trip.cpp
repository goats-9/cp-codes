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
 
vi p;
V<bool> c;
vvi adj;
int n, m, st, en;
 
bool dfs(int u, int pr) {
	c[u] = true;
	for (int x : adj[u]) { 
		if (x == pr) continue;
		if (c[x]) {
			st = x, en = u;
			return true;
		}
		p[x] = u;
		if (dfs(x, u)) return true;
	}
	return false;
}
 
int main() {
	cin >> n >> m;
	int x, y;
	c.assign(n + 1, false);
	p.assign(n + 1, -1);
	adj.assign(n + 1, vi());
	f(i, 0, m, 1) { 
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	st = -1, en = -1;
	f(i, 1, n + 1, 1) if (!c[i] && dfs(i, p[i])) break;	
	if (st == -1) cout << "IMPOSSIBLE\n";
	else { 
		vi path;
		path.pb(st);
		for (int u = en; u != st; u = p[u]) path.pb(u);
		path.pb(st); reverse(all(path));
		cout << path.size() << nl;
		for (int w : path) cout << w << " ";
		cout << nl;
	}
	return 0;
}