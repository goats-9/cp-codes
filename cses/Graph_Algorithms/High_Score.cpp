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
#define MININF -1000000000000000LL 
 
int n, m;
V<V<pii>> adj;
vll dis;
V<bool> vis;
 
bool bfs(int u) { 
	vis.assign(n + 1, false);
	vis[u] = true;
	queue<int> q; q.push(u);
	while (!q.empty()) { 
		int v1 = q.front(); q.pop();
		if (v1 == n) return true;
		f(i, 0, adj[v1].size(), 1) { 
			int v2 = adj[v1][i].first;
			if (!vis[v2]) { 
				q.push(v2);
				vis[v2] = true;
			}
		}
	}
	return false;
}
 
int main() {
	int a, b, x;
	cin >> n >> m;
	adj.assign(n + 1, V<pii>());
	dis.assign(n + 1, MININF);
	dis[1] = 0;
	f(i, 0, m, 1) { 
		cin >> a >> b >> x;
		adj[a].pb(pii(b, x));
	}
	f(k, 0, n, 1) { 
		f(i, 1, n + 1, 1) { 
			f(j, 0, adj[i].size(), 1) { 
				int u = adj[i][j].first, p = adj[i][j].second;
				dis[u] = max(dis[u], dis[i] + p);
			}
		}	
	}
	bool fl = false;
	V<bool> st(n + 1, false);
	queue<int> q; q.push(1);
	while (!q.empty()) { 
		int u = q.front(); q.pop();
		f(i, 0, adj[u].size(), 1) { 
			int v = adj[u][i].first;
			if (!st[v]) { 
				st[v] = true;
				q.push(v);
			}
		}
	}
	f(i, 1, n + 1, 1) { 
		f(j, 0, adj[i].size(), 1) { 
			int u = adj[i][j].first, p = adj[i][j].second;
			if (dis[u] < dis[i] + p && st[u] && bfs(u)) { 
				fl = true;
				break;
			}
		}
		if (fl) break;
	}
	if (fl) cout << -1 << nl;
	else cout << dis[n] << nl;
	return 0;
}