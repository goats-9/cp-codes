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

int ht(int a, vi &h) { 
	return max(max(h[a + 1], h[a - 1]) - h[a] + 1, 0);
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n;
		cin >> n;
		vi h(n);
		f(i, 0, n, 1) cin >> h[i];
		if (n % 2) {
			ll a = 0;
			f(i, 1, n - 1, 2) { 
				a += ht(i, h);
			}
			cout << a << "\n";
		} else {
			vll s(n);
			f(i, 1, n - 1, 1) s[i] = ht(i, h);
			f(i, 3, n - 1, 2) s[i] += s[i - 2];
			for (int i = n - 4; i >= 2; i -= 2) { 
				s[i] += s[i + 2];
			}
			ll ans = LLONG_MAX;
			f(i, 1, n - 1, 2) ans = min(ans, s[i] + (i + 3 < n - 1 ? s[i + 3] : 0));
			cout << min(ans, s[2]) << "\n";
		}
	}
	return 0;
}
