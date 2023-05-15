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
	int n, m, x, y, p, k; cin >> n >> m >> k;
	V<V<pll>> adj(n + 1, V<pll>());
	vvll dist(n + 1, vll(k,INF)); dist[1][0] = 0;
	f(i, 0, m, 1) { 
		cin >> x >> y >> p;
		adj[x].pb(pll(y, p));
	}
	priority_queue<pll, V<pll>, greater<pll>> pq; pq.push(pll(0, 1));
	while (!pq.empty()) { 
		ll d = pq.top().first, u = pq.top().second;	pq.pop();
		if (d > dist[u][k - 1]) continue;
		f(i, 0, adj[u].size(), 1) { 
			ll v = adj[u][i].first, w = adj[u][i].second;
			if (d + w < dist[v][k - 1]) { 
				dist[v][k - 1] = d + w;
				pq.push(pll(dist[v][k - 1], v));
				sort(all(dist[v]));
			}
		}
	}
	f(i, 0, k, 1) cout << dist[n][i] << " ";
	cout << nl;
	return 0;
}