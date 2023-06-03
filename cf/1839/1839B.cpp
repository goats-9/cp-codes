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
        int n;
        cin >> n;
        V<pll> param(n);
        vll choose(n+1);
        f(i,0,n,1) {
            cin >> param[i].first >> param[i].second;
            param[i].second = -param[i].second;
        }
        sort(all(param));
        ll ans = 0;
        ll on = 0, mxon = 0;
        f(i,0,n,1) {
            if (param[i].first > mxon) {
                ++on;
                mxon = max(mxon, on);
                choose[param[i].first]++;
                ll k = on;
                on -= choose[k];
                choose[k] = 0;
                ans -= param[i].second;
            }
        }
        cout << ans << nl;
	}
	return 0;
}
