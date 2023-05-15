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
		vector<double> c(n);
		int sum = 0;
		double chg = 0, chg1 =0, c0, c1;
		f(i, 0, n, 1) { cin >> c[i]; sum += int(100*c[i]); }
		if (sum % n) { 
			c0 = (sum/n + 1)/100.0;
			c1 = (sum/n)/100.0;
			f(i, 0, n, 1) chg += max(c[i] - c0, 0.0);
			f(i, 0, n, 1) chg1 += max(c1 - c[i], 0.0);
			chg = max(chg, chg1);
		} else { 
			c0 = (sum/n)/100.0;
			f(i, 0, n, 1) chg += max(c[i] - c0, 0.0);
		}
		printf("$%.2lf\n", chg);
	}
	return 0;
}
