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
#define INF 1000000000000000LL
 
int main() {
	int n, m, x, y, p; cin >> n >> m;
	V<V<pll>> adj(n + 1, V<pll>());
	V<V<pll>> ad(n + 1, V<pll>());
	vll dist(n + 1, INF); dist[1] = 0;
	vll dis(n + 1, INF); dis[n] = 0;
	f(i, 0, m, 1) { 
		cin >> x >> y >> p;
		adj[x].pb(pll(y, p));
		ad[y].pb(pll(x, p));
	}
	priority_queue<pll, V<pll>, greater<pll>> pq; pq.push(pll(0, 1));
	while (!pq.empty()) { 
		ll d = pq.top().first, u = pq.top().second;	pq.pop();
		if (d > dist[u]) continue;
		f(i, 0, adj[u].size(), 1) { 
			ll v = adj[u][i].first, w = adj[u][i].second;
			if (dist[u] + w < dist[v]) { 
				dist[v] = dist[u] + w;
				pq.push(pll(dist[v], v));
			}
		}
	}
	pq.push(pll(0, n));
	while (!pq.empty()) { 
		ll d = pq.top().first, u = pq.top().second;	pq.pop();
		if (d > dis[u]) continue;
		f(i, 0, ad[u].size(), 1) { 
			ll v = ad[u][i].first, w = ad[u][i].second;
			if (dis[u] + w < dis[v]) { 
				dis[v] = dis[u] + w;
				pq.push(pll(dis[v], v));
			}
		}
	}
	ll res = LLONG_MAX;
	f(i, 1, n + 1, 1) { 
		f(j, 0, adj[i].size(), 1) { 
			int u = adj[i][j].first, w = adj[i][j].second;
			res = min(res, dist[i] + dis[u] + (w/2));
		}
	}
	cout << res << nl;
	return 0;
}