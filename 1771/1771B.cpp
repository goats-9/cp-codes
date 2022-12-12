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
	ll t, n, m, x, y;
    cin >> t;
    while (t--) { 
		cin >> n >> m;
		vll a(n + 1, n + 1);
		f(i, 0, m, 1) {
			cin >> x >> y;
			if (x > y) a[y] = min(a[y], x);
			else a[x] = min(a[x], y);
		}
		ll ans = 0;
		ll i = 1;
		while (i <= n) { 
			ll k = 0;
			ll mn = a[i];
			while (i + k <= n && a[i + k] <= mn) mn = a[i + k], ++k;
			f(j, i, i + k, 1) ans += ll(mn - j);
			i += k;
		}
		cout << ans << nl;
	}
	return 0;
}
