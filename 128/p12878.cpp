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
	int u, v, w, p, t;
	V<V<pii>> adj;
    while (cin >> p >> t) { 
		vi dis1(p, INF);
		vi dis2(p, INF);
		dis1[0] = 0;
		dis2[p - 1] = 0;
		adj.assign(p, V<pii>());
		f(i, 0, t, 1) { 
			cin >> u >> v >> w;
			adj[u].pb(pii(v, w));
			adj[v].pb(pii(u, w));
		}
		priority_queue<pii> pq;
		pq.push(pii(0, 0));
		while (!pq.empty()) { 
			int v = -pq.top().second, cur_w = -pq.top().first;
			pq.pop();
			if (cur_w > dis1[v]) continue;
			f(i, 0, adj[v].size(), 1) { 
				int u = adj[v][i].first, dw = adj[v][i].second;
				if (dis1[v] + dw < dis1[u]) { 
					dis1[u] = dis1[v] + dw;
					pq.push(pii(-dis1[u], -u));
				} 
			}
		}
		pq.push(pii(0, -p + 1));
		while (!pq.empty()) { 
			int v = -pq.top().second, cur_w = -pq.top().first;
			pq.pop();
			if (cur_w > dis2[v]) continue;
			f(i, 0, adj[v].size(), 1) { 
				int u = adj[v][i].first, dw = adj[v][i].second;
				if (dis2[v] + dw < dis2[u]) { 
					dis2[u] = dis2[v] + dw;
					pq.push(pii(-dis2[u], -u));
				} 
			}
		}
		int cost = dis1[p - 1], ans = 0;
		f(i, 0, p, 1) { 
			f(j, 0, adj[i].size(), 1) { 
				int v = adj[i][j].first, w = adj[i][j].second;
				if (dis1[i] + w + dis2[v] == cost) ans += w;
			}
		}
		cout << 2*ans << nl;
	}
	return 0;
}
