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
		vll a(n);
		f(i, 0, n, 1) scanf("%lld", &a[i]);
		ll delta = 0, ans = 0, min = a[0];
		f(i, 1, n, 1) {
			a[i] -= delta;
			if (min > a[i]) {
				ans += min - a[i];
				min = a[i];
			} else if (min < a[i]) { 
				delta += a[i] - min;
				ans += a[i] - min;
			}
		}
		printf("%lld\n", ans + abs(min));
	}
	return 0;
}
