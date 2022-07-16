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

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n;
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int i = 0;
		ll ans = 0;
		while (i < n - 1) { 
			if (a[i]) { 
				int k = 1;
				ans += a[i];
				while (i + k < n - 1 && !a[i + k]) ++k;
				i += k;
				ans += (k - 1);
			} else ++i;
		}
		cout << ans << "\n";
	}
	return 0;
}
