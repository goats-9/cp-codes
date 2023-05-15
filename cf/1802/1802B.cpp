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
        vi a(n);
        f(i,0,n,1) cin >> a[i];
        int male = 0, ans = 0, unc = 0;
        bool fl = false;
        f(i,0,n,1) {
            if (a[i] == 1) ++unc;
            else if (unc) {
                if (fl) {
                    ans = max(ans, 1 + (male>>1) + (male&1) + unc);
                    male += unc, unc = 0;
                } else {
                    ans = max(ans, unc);
                    male += max(0,unc - 1), unc = 0;
                    fl = true;
                }
            }
        }
        if (fl) ans = max(ans, 1 + (male>>1) + (male&1) + unc);
        else ans = max(unc, ans);
        cout << ans << nl;
	}
	return 0;
}
