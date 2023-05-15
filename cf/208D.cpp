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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int n; cin >> n;
    vll a(n);
    f(i, 0, n, 1) cin >> a[i];
    vll g(5); cin >> g[0] >> g[1] >> g[2] >> g[3] >> g[4];
    vll pr(5);
    ll bal = 0;
    f(i, 0, n, 1) {
        bal += a[i];
        while (bal >= g[0]) {
            auto it = --upper_bound(all(g), bal);
            ll cost = *it;
            int pos = it - g.begin();
            pr[pos] += (bal/cost);
            bal %= cost;
        }
    }
    f(i, 0, 5, 1) cout << pr[i] << " ";
    cout << nl << bal << nl;
	return 0;
}