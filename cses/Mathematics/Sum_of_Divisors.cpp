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
#define TINV (ll)500000004

int main() {
    ll n;
    cin >> n;
    ll ans = 0, d = 1;
    while (d <= n) {
        ll div = n/d;
        ll end = n/div;
        ans = (ans + ((((div%MOD1)*TINV)%MOD1)*(((end-d+1)%MOD1)*((end+d)%MOD1)%MOD1)))%MOD1;
        d = end + 1;
    }
    cout << ans << nl;
	return 0;
}
