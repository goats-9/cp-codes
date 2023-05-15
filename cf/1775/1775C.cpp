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
#define MOD (int)1e9 + 7
#define LSOne(s) (s & (-s))

int main() {
	int t;
    cin >> t;
    ll n, x;
    while (t--) { 
        cin >> n >> x;
        if (n == 0) {
            if (x == 0) cout << 0 << nl;
            else cout << -1 << nl;
            continue;
        }
        bool fl = true;
        //Check 0-1 match
        f(i, 0, 63, 1) { 
            ll k = (1LL << i);
            if ((n&k) < (x&k)) {fl = false; break;}
        }
        if (!fl) {cout << -1 << nl; continue;} 
        if (x == 0) { 
            if (n == 0) cout << 0 << nl;
            else { 
                for (int i = 62; i >= 0; i--) { 
                    ll k = (1LL<<i);
                    if (n&k) {cout << k*2LL << nl; break;}
                }
            }
        } else { 
            ll y = LSOne(x), z = n^x;
            if (y < z) cout << -1 << nl;
            else {
                if (z*2LL >= y) cout << - 1 << nl;
                else if (z == 0) cout << n << nl;
                else { 
                    int exp = 1 + floor(log2l(z));
                    cout << (x|(1LL<<exp)) << nl;
                }
            }
        }
	}
	return 0;
}
