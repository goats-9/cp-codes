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
	int t;
	cin >> t;
	while (t--) { 
		string s;
		int n, m;
		cin >> s >> n >> m;
		vvi a(n, vi(m));
		V<P<int, pii>> pt;
		f(i,0,n,1) f(j,0,m,1) {
			cin >> a[i][j];
			pt.pb({a[i][j], {i, j}});
		}
		vvi dp(n, vi(m, 1));
		sort(all(pt));
		vi dx = {-1,1,0,0};
		vi dy = {0,0,1,-1};
		for (auto &[h, p] : pt) {
			auto &[i, j] = p;
			f(k,0,4,1) {
				int u = i + dx[k], v = j + dy[k];
				if (u >= 0 && u < n && v >= 0 && v < m && a[u][v] < a[i][j]) {
					dp[i][j] = max(dp[i][j], 1 + dp[u][v]);
				}
			}
		}
		int mx = 0;
		f(i,0,n,1) mx = max(mx, *max_element(all(dp[i])));
		cout << s << ": " << mx << nl;
	}
	return 0;
}
