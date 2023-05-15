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

int main() {
	int t;
    ll l, r;
	cin >> t;
    while (t--) { 
        cin >> l >> r;
        ll p = l;
        int mx = 0;
        while ((p<<1) <= r) {
            p <<= 1;
            ++mx;
        }
        ll x = 1 << mx, y = 3*(1<<(mx-1));
        cout << mx+1 << ' ';
        if (r/y >= l) cout << ((r/y-l+1)*(mx+1) + (r/x-r/y))%MOD << nl;
        else cout << (r/x-l+1)%MOD << nl;
	}
	return 0;
}
