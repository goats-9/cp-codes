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
#define INF 1000000000
 
int main() {
	int n, m, u, v;
	cin >> n >> m;
	vi dist(n + 1, INF);
	dist[1] = 0;
	vi p(n + 1, 0), indeg(n + 1, 0);
	vvi adj(n + 1, vi()), badj(n + 1, vi());
	f(i, 0, m, 1) { 
		cin >> u >> v;
		adj[u].pb(v);
		indeg[v]++;
		badj[v].pb(u);
	}
	queue<int> q;
	f(i, 1, n + 1, 1) if (!indeg[i]) q.push(i);
	while (!q.empty()) { 
		int u = q.front(); q.pop();
		for (auto v : adj[u]) { 
			indeg[v]--;
			if (!indeg[v]) q.push(v);
		}
		for (auto v : badj[u]) { 
			if (dist[v] - 1 < dist[u]) { 
				dist[u] = dist[v] - 1;
				p[u] = v; 
			}
		}
	}
	if (dist[n] < 0) { 
		vi path;
		for (int z = n; z != 0; z = p[z]) path.pb(z);
		reverse(all(path));
		cout << path.size() << nl;
		for (auto z : path) cout << z << " ";
		cout << nl;
	} else cout << "IMPOSSIBLE\n";
	return 0;
}