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
#define MOD (ll)998244353
#define N (int)2e5

ll modpow(ll n, ll k) { 
    if (k == 0) return 1;
    ll y = modpow(n, k>>1);
    ll z = (y*y)%MOD;
    if (k%2) return (z*(n%MOD))%MOD;
    return z;
}

int main() {
	ll t, n;
    cin >> t;
    while (t--) { 
        cin >> n;
        vi a(n), b(n, 1);
        int z = 0;
        f(i, 0, n, 1) { cin >> a[i]; z += (1 - a[i]); }
        f(i, 0, z, 1) b[i] = 0;
        int p = 0;
        f(i, 0, n, 1) if (a[i] > b[i]) ++p;
        ll num = ((n*(n - 1))>>1) % MOD;
        ll ans = 0;
        for (ll i = 1; i < p + 1; i++) ans = (ans + modpow(i*i, MOD - 2))%MOD;
        cout << (ans*num)%MOD << nl;
	}
	return 0;
}
