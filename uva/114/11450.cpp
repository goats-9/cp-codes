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
		int m, c;
		cin >> m >> c;
		vvi a(c+1, vi());
		f(i,1,c+1,1) {
			int k;
			cin >> k;
			f(j,0,k,1) {
				int x;
				cin >> x;
				a[i].pb(x);
			}
		}
		vvi dp(c+1, vi(m+1));
		dp[0][0] = 1;
		f(i,1,c+1,1) {
			for (auto x : a[i]) {
				f(j,0,m+1,1) {
					if (j - x >= 0) dp[i][j] |= dp[i-1][j-x];
				}
			}
		}
		int mx = -1;
		f(j,0,m+1,1) if (dp[c][j]) mx = j;
		if (mx == -1) cout << "no solution\n";
		else cout << mx << nl;
	}
	return 0;
}
