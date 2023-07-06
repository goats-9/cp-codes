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

int main() {
	int t;
	cin >> t;
	while (t--) { 
        int n, k;
        cin >> n >> k;
        vi a(n);
        f(i,0,n,1) cin >> a[i];
        vi vals;
        int ans = 0;
        f(i,0,n-1,1) {
            int x = abs(a[i]-a[i+1]);
            ans += x;
            vals.pb(x);
        }
        sort(rall(vals));
        f(i,0,k-1,1) ans -= vals[i];
        cout << ans << nl;
	}
	return 0;
}
