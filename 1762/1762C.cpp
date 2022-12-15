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
#define MOD (ll)998244353
#define N 200000

vll fac(N + 1), invmod(N + 1), invfac(N + 1);

ll cmbmod(ll n, ll k) { 
    if (n < 0 || k < 0 || k > n) return 0;
    return ((fac[n]*invfac[n - k])%MOD*invfac[k])%MOD;
}

int main() {
    fac[0] = invmod[0] = invfac[0] = 1;
    fac[1] = invmod[1] = invfac[1] = 1;
    f(i, 2, N + 1, 1) fac[i] = (ll(i)*fac[i - 1])%MOD;
    f(i, 2, N + 1, 1) invmod[i] = ((-ll(MOD/i)*invmod[MOD%i])%MOD + MOD)%MOD;
    f(i, 2, N + 1, 1) invfac[i] = (invfac[i - 1]*invmod[i])%MOD;
	int t, n;
    string s;
    scanf("%d", &t);
    while (t--) { 
        cin >> n >> s;
        vi oc(n + 1);
        oc[1] = s[0] - '0';
        f(i, 2, n + 1, 1) { 
            oc[i] = oc[i - 1];
            if (s[i - 1] == '1') ++oc[i];
        }
        vll dp(n + 1);
        dp[1] = 1;
        f(i, 2, n + 1, 1) { 
            int f = oc[i - 1];
            if (s[i - 2] == '0') f = i - 1 - f;
            if (s[i - 1] == s[i - 2]) {
                dp[i] = (2*dp[i - 1])%MOD;
            } else {
                dp[i] = 1;
            }
        }
        f(i, 2, n + 1, 1) dp[i] = (dp[i] + dp[i - 1])%MOD;
        cout << dp[n] << nl;
	}
	return 0;
}
