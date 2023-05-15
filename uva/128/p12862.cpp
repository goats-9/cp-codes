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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

vi fr, ld, vis, cost;
V<V<pii>> adj;
int ans, mxf;

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) { 
		int v = q.front();
		q.pop();
		vis[v] = 1;
		f(i, 0, adj[v].size(), 1) { 
			int u = adj[v][i].first, pc = adj[v][i].second;
			if (!vis[u]) {
				ans -= pc*max(0, fr[u] - 1);
				cost[u] = pc + cost[v];
				q.push(u);
			}
		}
	}
}

void dfs(int i) { 
	vis[i] = 1;
	f(j, 0, adj[i].size(), 1) { 
		int v = adj[i][j].first;
		if (!vis[v]) {
			dfs(v);
			fr[i] += fr[v];
		}
	}
}

int main() {
	int n, f, a, b, c;
    while (cin >> n >> f) { 
		cost.assign(n + 1, 0);
		adj.assign(n + 1, V<pii>());
		fr.assign(n + 1, 0);
		vis.assign(n + 1, 0);
		ld.assign(n + 1, 0);
		f(i, 0, n - 1, 1) {
			cin >> a >> b >> c;
			adj[a].pb(mp(b, c));
			adj[b].pb(mp(a, c));
		}
		f(i, 0, f, 1) {cin >> a; ld[a] = fr[a] = 1;}
		ans = mxf = 0;
		dfs(1); vis.assign(n + 1, 0); bfs();
		f(i, 2, n + 1, 1) { 
			if (ld[i]) { 
				ans += cost[i];
				mxf = max(mxf, cost[i]);
			}
		}
		ans -= mxf;
		cout << ans << nl;
	}
	return 0;
}
