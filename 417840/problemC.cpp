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

ll tot(vll &fac, int i, ll m) { 
    if (i == (int)fac.size()) return m;
    return tot(fac, i + 1, m) - tot(fac, i + 1, m/fac[i]);
}

int main() {
	int t;
    ll n, m;
    cin >> t;
    while (t--) { 
        cin >> n >> m;
        vll a(n);
        f(i, 0, n, 1) cin >> a[i];
        bool fl = true;
        f(i, 0, n - 1, 1) if (a[i]%a[i + 1]) {fl = false; break;}
        if (!fl) {cout << "0\n"; continue;} 
        ll ans = 1;
        f(i, 1, n, 1) {
            if (a[i - 1] == 1) {ans = (ans*m)%MOD; continue;}
            ll x = a[i - 1]/a[i];
            vll fac;
            for (ll i = 2; i*i <= x; i++) { 
                if (!(x%i)) fac.pb(i);
                while (!(x%i)) x /= i;
            }
            if (x > 1) fac.pb(x);
            ll mul = tot(fac, 0, m/a[i]);
            ans = (ans*mul)%MOD;
        }
        cout << ans << nl;
	}
	return 0;
}
