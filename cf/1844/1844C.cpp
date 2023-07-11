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
        int fl = 0;
        vll a, b;
        ll mx = -1e18;
        f(i,0,n,1) {
            ll x; cin >> x;
            if (fl) a.pb(x);
            else b.pb(x);
            fl = 1 - fl;
            mx = max(mx, x);
        }
        sort(rall(a)), sort(rall(b));
        if (a.size() && a.front() >= 0) {
            ll sm = 0;
            for (auto x : a) {
                if (x >= 0) sm += x;
                else break;
            }
            mx = max(mx, sm);
        }
        if (b.size() && b.front() >= 0) {
            ll sm = 0;
            for (auto x : b) {
                if (x >= 0) sm += x;
                else break;
            }
            mx = max(mx, sm);
        }
        cout << mx << nl;
	}
	return 0;
}
