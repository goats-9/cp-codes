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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7

int main() {
	int n;
	while (cin >> n && n) { 
		vi a(1 << n), pt(1 << n);
		f(i, 0, (1 << n), 1) cin >> a[i];
		f(i, 0, (1 << n), 1) {
			f(j, 0, n, 1) {
				int k = i^(1 << j);
				pt[i] += a[k];
			}
		}
		int ans = 0;
		f(i, 0, (1 << n), 1) { 
			f(j, 0, n, 1) { 
				int k = i^(1 << j);
				ans = max(ans, pt[i] + pt[k]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
