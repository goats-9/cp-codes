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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7
#define INF int(1e9)

int analyze(int x, int y, int z) { 
	int xy = min(x, y), yz = min(y, z), xz = min(x, yz);
	vi el = {xy, xz, yz};
	sort(el.begin(), el.end());
	return min(el[0] + el[1], el[2]);
}

int main() {
	int t, n, k;
    scanf("%d", &t);
    while (t--) { 
		int ci = 0, mx = 0;
		cin >> n >> k;
		vi a(n);
		V<pii> b(n);
		f(i, 0, n, 1) { 
			cin >> a[i];
			if (a[i] == INF) ++ci;
			else mx = max(mx, a[i]);
		}
		if (n >= 3) {
			if (k  + ci >= 3) cout << INF << nl;
			else if (k + ci == 2) {
				cout << min(2*mx, INF) << nl;
			} else { 
				int ans = 0;
				f(i, 0, n - 2, 1) {
					int x = min(a[i], a[i + 2]), y = max(a[i], a[i + 2]);
					ans = max(ans, min(2*x, y));
				}
				if (a[1] > a[2]) ans = max(ans, min(2*a[2], a[1]));
				else ans = max(ans, a[1]);
				if (a[n - 2] > a[n - 3]) ans = max(ans, min(2*a[n - 3], a[n - 2]));
				else ans = max(ans, a[n - 1]);
				cout << ans << nl;
			}
		} else if (n == 2) { 
			if (k + ci == 2) cout << INF << nl;
			else cout << max(a[0], a[1]) << nl;
		}
	}
	return 0;
}
