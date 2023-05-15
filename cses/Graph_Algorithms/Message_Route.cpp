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
 
vi vis, p;
vvi adj;
int n, m;
 
void bfs() { 
	queue<int>q; q.push(1);
	vis[1] = 1;
	while (!q.empty()) { 
		int u = q.front(); q.pop();
		f(i, 0, adj[u].size(), 1) { 
			int v = adj[u][i];
			if (!vis[v]) { 
				q.push(v);
				vis[v] = 1;
				p[v] = u;
				if (v == n) return;
			}
		}
	}
}
 
int main() {
	cin >> n >> m;
	int x, y;
	vis.assign(n + 1, 0);
	p.assign(n + 1, 0);
	adj.assign(n + 1, vi());
	f(i, 0, m, 1) { 
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	} 
	bfs();
	if (vis[n]) {
		int u = n;
		vi path;
		while (u != 0) {
			path.pb(u);
			u = p[u];
		}
		reverse(all(path));
		cout << path.size() << nl;
		for (auto x : path) cout << x << " ";
		cout << nl;
	} else cout << "IMPOSSIBLE\n";
	return 0;
}