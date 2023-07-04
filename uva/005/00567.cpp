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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353
#define INF 1000

int main() {
	int tc = 0;
	int sz;
	while (cin >> sz) {
		++tc;
		vvi adj(21, vi(21, INF));
		f(j,0,sz,1) {
			int u;
			cin >> u;
			adj[1][u] = 1, adj[u][1] = 1;
		}
		f(i,2,20,1) {
			cin >> sz;
			f(j,0,sz,1) {
				int u;
				cin >> u;
				adj[i][u] = 1, adj[u][i] = 1;
			}
		}
		f(k,1,21,1) {
			f(i,1,21,1) {
				f(j,1,21,1) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int m; cin >> m;
		cout << "Test Set #" << tc << nl;
		f(i,0,m,1) {
			int u, v;
			cin >> u >> v;
			printf("%2d to %2d: %d\n", u, v, adj[u][v]);
		}
		cout << nl;
	}
	return 0;
}
