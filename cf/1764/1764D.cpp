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
#define MOD (int)1e9 + 7

ll n, p;

ll f1(ll n, ll k) { 
    ll ret = 1;
    while (n > k) { 
        ret = (ret * n)%p;
        --n;
    }
    return ret;
}

ll f2(ll x) {
    if (x == 0) return 1;
    return (1 + x*f2(x - 1))%p;
} 

ll f3(ll x, ll i) { 
    if (i == x - 1) return 1;
    return (1 + (x + i)*(x - 1 - i)*f3(x, i + 1))%p;
}

int main() {
    cin >> n >> p;
    ll ans;
    if (n%2) { 
        ll k = n/2;
        ans = (f1(k, 0)*n)%p;
        ans = (ans*f3(k, 0))%p;
    } else { 
        ll k = n/2 + 1;
        ans = (2*f1(n,k)*f2(n-k))%p;
    }
    cout << ans << nl;
	return 0;
}