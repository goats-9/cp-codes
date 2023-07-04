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
	int n;
	while (cin >> n && n) {
		vvi adj(n+1, vi(n+1, INF));
		int u;
		while (cin >> u && u) {
			int v;
			while (cin >> v && v) adj[u][v] = 1; 
		}
		f(k,1,n+1,1)
			f(i,1,n+1,1)
				f(j,1,n+1,1)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		int m; cin >> m;
		f(i,0,m,1) {
			int u;
			cin >> u;
			vi un;
			f(i,1,n+1,1) if (adj[u][i] == INF) un.pb(i);
			cout << un.size();
			for (auto v : un) cout << ' ' << v;
			cout << nl;
		}
	}
	return 0;
}
