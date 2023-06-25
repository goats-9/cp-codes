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

ll powexp(ll a, ll x) {
    if (!x) return 1;
    ll y = pow(a, (x>>1));
    ll z = y*y;
    if (x&1) z *= a;
    return z;
}

int main() {
    ll a, b;
    while (cin >> a >> b && a) {
        if (a == 1) {
            cout << "0 1\n";
            continue;
        }
        if (b == 1) {
            ll a1 = log2l(a);
            cout << a1 << ' ' << 2*a - 1 << nl;
            continue;
        }
        double n = 2.0;
        double r = logl(a)/logl(b);
        while (fabsl((logl(n+1)/logl(n)) - r) > 1e-12) n++;
        ll a1 = (b-1)/(n-1);
        ll a2 = n*(a-b) + a;
        cout << a1 << ' ' << a2 << nl;
    }
	return 0;
}
