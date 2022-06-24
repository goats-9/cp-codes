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
				int n, m, x = 0, y = 0, ans = 0;
				scanf("%d %d", &n, &m);
				vi a(n);
				f(i, 0, n, 1) scanf("%d", &a[i]);
				int i = 0;
				while (i < n) {
					x += a[i];
					if (x > m) {
						x -= a[i];
						m -= x;
						while (i < n) {y += a[i]; ++i;}
						ans = y - m;
					}
					++i;
				}
				if (i == n) printf("0\n");
				else printf("%d\n", ans);
			}
			return 0;
}
