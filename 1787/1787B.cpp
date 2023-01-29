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

int main() {
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        mii fac_ctr;
        for (int i = 2; i*i <= n; i++) {
            while (!(n%i)) {
                n /= i;
                fac_ctr[i]++;
            }
        }
        if (n > 1) fac_ctr[n] = 1;
        ll ans = 0;
        while (1) {
            ll p = 1;
            for (auto &ele : fac_ctr) {
                if (ele.second) {
                    p *= ele.first;
                    --ele.second;
                }
            }
            if (p == 1) break;
            ans += p;
        }
        cout << ans << nl;
	}
	return 0;
}
