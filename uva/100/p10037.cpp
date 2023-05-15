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

int main() {
	int tc, n;
    scanf("%d", &tc);
	f(k, 0, tc, 1) {
		if (k) cout << nl;
		cin >> n;
		int ans = 0;
		stringstream ss;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		sort(a.begin(), a.end());
		int c = n - 1;
		while (c >= 3) {
			int t1 = a[0] + 2*a[1] + a[c], t2 = 2*a[0] + a[c] + a[c - 1];
			if (t1 < t2) { 
				ss << a[0] << " " << a[1] << nl;
				ss << a[0] << nl;
				ss << a[c - 1] << " " << a[c] << nl;
				ss << a[1] << nl;
			} else { 
				ss << a[0] << " " << a[c] << nl;
				ss << a[0] << nl;
				ss << a[0] << " " << a[c - 1] << nl;
				ss << a[0] << nl;
			}
			ans += min(t1, t2);
			c -= 2;
		}
		if (c == 2) { 
			ss << a[0] << " " << a[2] << nl;
			ss << a[0] << nl;
			ss << a[0] << " " << a[1] << nl;
			ans += a[0] + a[1] + a[2];
		} else if (c == 1) { 
			ss << a[0] << " " << a[1] << nl;
			ans += a[1];
		} else { 
			ss << a[0] << nl;
			ans += a[0];
		}
		cout << ans << nl << ss.str();
	}
	return 0;
}
