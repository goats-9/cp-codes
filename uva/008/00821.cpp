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

int main() {
	int u, v;
	int tc = 0;
	while (cin >> u >> v && u) {
		set<int> st;
		V<pii> el;
		st.insert(u), st.insert(v);
		el.pb({u, v});
		while (cin >> u >> v && u) {
			st.insert(u), st.insert(v);
			el.pb({u, v});
		}
		mii node;
		int i = 0;
		for (auto u : st) node[u] = i++;
		for (auto &[u, v] : el) u = node[u], v = node[v];
		int sz = st.size();
		vvi adj(sz, vi(sz, MOD1));
		for (auto &[u, v] : el) adj[u][v] = 1;
		f(i,0,sz,1) adj[i][i] = 0;
		f(k,0,sz,1)
			f(i,0,sz,1)
				f(j,0,sz,1)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		int ans = 0;
		f(i,0,sz,1) f(j,0,sz,1) ans += adj[i][j];
		printf("Case %d: average length between pages = %.3lf clicks\n", ++tc, (double)ans/(sz*(sz-1)));
	}
	return 0;
}
