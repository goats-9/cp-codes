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
#define INF (int)1e9

int main() {
	int c, v, x, y, z, c1, c2, g, p, q;
    while (cin >> c >> v) { 
		V<V<pii>> rd(c + 1, V<pii>()), adj(c + 1, V<pii>());
		f(i, 0, v, 1) { 
			cin >> c1 >> c2 >> g;
			rd[c1].pb(pii(c2, g));
			rd[c2].pb(pii(c1, g));
		}
		f(i, 1, c + 1, 1) { 
			x = i;
			f(j, 0, rd[i].size(), 1) { 
				y = rd[i][j].first, p = rd[i][j].second;
				f(k, 0, rd[y].size(), 1) { 
					z = rd[y][k].first, q = rd[y][k].second;
					if (z != x) adj[x].pb(pii(z, p + q));
				}
			}
		}
		vi dis(c + 1, INF);
		dis[1] = 0;
		priority_queue<pii> pq;
		pq.push(mp(0, -1));
		while (!pq.empty()) { 
			int v = -pq.top().second, cw = -pq.top().first;
			pq.pop();
			if (cw > dis[v]) continue;
			f(i, 0, adj[v].size(), 1) { 
				int u = adj[v][i].first, dw = adj[v][i].second;
				if (dis[v] + dw < dis[u]) { 
					dis[u] = dis[v] + dw;
					pq.push(pii(-dis[u], -u));
				}
			}
		}
		if (dis[c] == INF) cout << "-1\n";
		else cout << dis[c] << nl;
	}
	return 0;
}
