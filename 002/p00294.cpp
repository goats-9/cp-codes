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
	ll t, a, b;
	scanf("%lld", &t);
	while (t--) { 
		scanf("%lld %lld", &a, &b);
		ll mx = 0, mxn = 0;
		f(i, a, b + 1, 1) {
			ll ans = 0;
			double x = sqrt(i);
			f(j, 1, x + 1, 1) { 
				if (!(i%j)) ans += 2;
			}
			if (x == int(x)) ans--;
			if (mx < ans) {mx = ans; mxn = i;}
		}
		cout << "Between " << a << " and " << b << ", " << mxn << " has a maximum of " << mx << " divisors.\n";
	}
	return 0;
}
