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

ll modexp(ll a, ll b) {
    if (!a) return 0;
    if (!b) return 1;
    ll y = modexp(a, b>>1);
    ll z = y*y%MOD1;
    if (b%2) z = a*z%MOD1;
    return z;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(26); 
    V<pll> words(n);
    f(i,0,n,1) cin >> words[i].first >> words[i].second;
    f(i,0,m,1) {
        char x;
        cin >> x;
        ++a[x-'A'];
    }
    vll dp(n+1), dptot(k+1); 
    dptot[0] = 1;
    f(j,1,k,1)
        for (auto &[s, c]: words) 
            if (j - s >= 0) 
                dptot[j] = (dptot[j] + dptot[j - s])%MOD1; 
    for (auto &[s, c]: words) 
        if (k - s >= 0) 
            dp[c] = (dp[c] + dptot[k - s]) % MOD1;
    ll ans = 1;
    f(j,0,26,1) {
        ll tmp = 0, pw = a[j];
        if (!pw) continue;
        f(i,1,n+1,1) tmp = (tmp + modexp(dp[i], pw))%MOD1;
        ans = (ans*tmp)%MOD1;
    }
    cout << ans << nl;
	return 0;
}
