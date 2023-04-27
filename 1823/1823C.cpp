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
        vi pr;
        f(i,0,n,1) {
            int k = a[i];
            for (int j = 2; j*j <= k; j++) {
                while (k%j == 0) {
                    k /= j;
                    pr.pb(j);
                }
            }
            if (k > 1) pr.pb(k);
        }
        sort(all(pr));
        int i = 0, sz = pr.size();
        int oc = 0, ans = 0;
        while (i < sz) {
            int k = 0;
            while (i + k < sz && pr[i] == pr[i + k]) ++k;
            ans += (k/2);
            oc += (k%2);
            i += k;
        }
        cout << ans + (oc/3) << nl;
	}
	return 0;
}
