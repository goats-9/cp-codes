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
#define N 1000001

ll modexp(ll a, ll b, ll c) {
    if (b == 0) return 1;
    ll z = modexp(a, (b>>1), c);
    ll y = z*z%c;
    if (b%2) y = y*a%c;
    return y;
}

ll modinv(ll a) { return modexp(a, MOD1-2, MOD1); }

int main() {
    vll fac(N);
    fac[0] = 1;
    f(i,1,N,1) fac[i] = fac[i-1]*i%MOD1;
	int t;
	cin >> t;
	while (t--) { 
        ll a, b;
        cin >> a >> b;
        cout << (fac[a]*modinv(fac[b])%MOD1)*modinv(fac[a-b])%MOD1 << nl;
	}
	return 0;
}
