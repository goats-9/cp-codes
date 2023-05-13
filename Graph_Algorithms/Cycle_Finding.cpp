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
 
int n, m;
V<V<pii>> adj;
vll dis;
 
int main() {
	int a, b, x;
	cin >> n >> m;
	adj.assign(n + 1, V<pii>());
	dis.assign(n + 1, INF);
	vi par(n + 1, -1);
	dis[1] = 0;
	f(i, 0, m, 1) { 
		cin >> a >> b >> x;
		adj[a].pb(pii(b, x));
	}
	f(k, 0, n - 1, 1) { 
		f(i, 1, n + 1, 1) { 
			f(j, 0, adj[i].size(), 1) { 
				int u = adj[i][j].first, p = adj[i][j].second;
				if (dis[u] > dis[i] + p) { 
					dis[u] = dis[i] + p;
					par[u] = i;
				}
			}
		}	
	}
	int vt = -1;
	f(i, 1, n + 1, 1) { 
		f(j, 0, adj[i].size(), 1) { 
			int u = adj[i][j].first, p = adj[i][j].second;
			if (dis[u] > dis[i] + p) { 
				vt = u;
				par[u] = i;
			}
			if (vt != -1) { 
				f(i, 0, n, 1) vt = par[vt];
				cout << "YES\n";
				vi path; path.pb(vt);
				for (int m = par[vt]; m != vt; m = par[m]) path.pb(m);
				path.pb(vt);
				reverse(all(path));
				for (auto z : path) cout << z << " ";
				cout << nl;
				return 0;
			} 
		}
	}
	cout << "NO\n";
	return 0;
}