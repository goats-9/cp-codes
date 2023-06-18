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
	int n;
    cin >> n;
    vi a(n);
    f(i,0,n,1) cin >> a[i];
    mii dp;
    int ans = 0, last = 0;
    for (auto x : a) {
        dp[x] = max(dp[x], dp[x - 1] + 1);
        if (ans < dp[x]) ans = dp[x], last = x;
    }
    vi res;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == last) res.pb(i + 1), --last;
    }
    reverse(all(res));
    cout << res.size() << nl;
    for (auto k : res) cout << k << ' ';
    cout << nl;
	return 0;
}
