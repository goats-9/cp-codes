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
	int n, m, u, v, w;
	while (cin >> n >> m && n) { 
		vi dis(n + 1, -INF);
		V<V<pii>> adj(n + 1, V<pii>());
		dis[1] = 0;
		f(i, 0, m, 1) { 
			cin >> u >> v >> w;
			adj[u].pb(pii(v, w));
		}
		queue<int> q; q.push(1);
		int fl = 0;
		vi cnt(n + 1, 0), inq(n + 1, 0);
		while (!q.empty()) { 
			int u = q.front();
			q.pop();
			inq[u] = 0;
			cnt[u]++;
			if (cnt[u] > n) {fl = 1; break;}
			f(i, 0, adj[u].size(), 1) { 
				int v = adj[u][i].first, dw = adj[u][i].second;
				if (dis[v] < dis[u] + dw) { 
					dis[v] = dis[u] + dw;
					if (!inq[v]) {q.push(v); inq[v] = 1;}
				}
			}
		}
		if (fl) cout << "Unlimited!\n";
		else { 
			int ans = 0;
			f(i, 1, n + 1, 1) if (dis[i] != INF) ans = max(ans, dis[i]);
			cout << ans << nl;
		}
	}
	return 0;
}
