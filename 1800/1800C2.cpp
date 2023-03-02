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
        vll a(n);
        f(i,0,n,1) cin >> a[i];
        multiset<ll> pow;
        int i = 0;
        ll sm = 0;
        while (i < n) {
            int k = 0, l = 0;
            ll tsm = 0;
            while (i + k < n && a[i+k]) {
                pow.insert(a[i+k]);
                ++k;
            }
            i += k;
            while (i + l < n && !a[i+l]) {
                ++l;
                if (!pow.empty()) {
                    tsm += *pow.rbegin();
                    pow.erase(--pow.end());
                }
            }
            i += l;
            sm += tsm;
        }
        cout << sm << nl;
	}
	return 0;
}
