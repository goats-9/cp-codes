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
    vll pw = {1,10,100,1000,10000,100000,1000000};
	while (t--) { 
        ll a, b, c, k;
        cin >> a >> b >> c >> k;
        ll mx = max(a, b), lwa = pw[a-1], upa = pw[a]-1, lwb = pw[b-1], upb = pw[b]-1, lwc = pw[c-1], upc = pw[c]-1;
        if ((c == mx) || (c == mx + 1)) {
            vll ans;
            ll add = 0;
            f(i,lwa,upa+1,1) {
                add += max(0LL, min(i + upb, upc) - max(lwc, i + lwb) + 1);
                ans.pb(add);
            }
            // for (auto l : ans) cout << l << ' ';
            // cout << nl;
            int pos = lower_bound(all(ans), k) - ans.begin();
            if (pos == (int)ans.size()) cout << -1 << nl;
            else {
                ll A = lwa + pos, B = min(A + upb, upc) - A - (ans[pos] - k);
                cout << A << " + " << B << " = " << A+B << nl;
            }
        } else cout << -1 << nl;
	}
	return 0;
}
