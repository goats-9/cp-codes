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
#define MOD (ll)1000000007

int main() {
	int t;
    ll n;
    cin >> t;
    while (t--) { 
        cin >> n;
        ll ans = 1011;
        if (n%3 == 0) {
            ans = ans*(n/3)%MOD;
            ans = ans*(n + 1)%MOD;
            ans = ans*(4*n - 1)%MOD;
        } else if (n%3 == 1) { 
            ans = ans*((4*n - 1)/3)%MOD;
            ans = ans*(n + 1)%MOD;
            ans = ans*(n)%MOD;
        } else { 
            ans = ans*((n + 1)/3)%MOD;
            ans = ans*(n)%MOD;
            ans = ans*(4*n - 1)%MOD;
        }
        cout << ans << nl;
	}
	return 0;
}
