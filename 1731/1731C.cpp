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
#define N (int)2e5

int main() {
	ll t, n;
    cin >> t;
    while (t--) { 
        ll ctr = 0;
        cin >> n;
        int mx = 0;
        vi a(n + 1), x(n + 1);
        f(i, 1, n + 1, 1) {cin >> a[i]; x[i] = a[i] ^ x[i - 1]; mx = max(mx, x[i]);}
        vi cnt(mx + 1);
        f(i, 0, n + 1, 1) ++cnt[x[i]];
        ll ans = (n*(n + 1))/2;
        f(i, 0, n + 1, 1) {
            for (int j = 0; j < 1000; j++) if ((x[i]^(j*j)) <= mx) ctr += cnt[x[i]^(j*j)];
            --ctr;
        }
        cout << ans - (ctr/2) << nl;
	}
	return 0;
}
