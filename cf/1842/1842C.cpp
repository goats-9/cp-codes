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
        int n; cin >> n;
        vi a(n+1), val(n+1,-(n+1)), dp(n+1), vis(n+1);
        f(i,1,n+1,1) cin >> a[i];
        f(i,1,n+1,1) {
            if (!vis[a[i]]) dp[i] = dp[i-1];
            else dp[i] = max(dp[i-1], i + val[a[i]]);
            vis[a[i]] = 1;
            val[a[i]] = max(val[a[i]], dp[i-1]-(i-1));
        }
        cout << dp[n] << nl;
	}
	return 0;
}
