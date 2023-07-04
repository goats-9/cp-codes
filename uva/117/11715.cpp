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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	int n;
	int tc = 0;
	while (cin >> n && n) {
		tc++;
		double u, v, t, a, s;
		if (n == 1) {
			cin >> u >> v >> t;
			a = (v - u)/t;
			s = u*t + 0.5*a*t*t;
			printf("Case %d: %.3lf %.3lf\n", tc, s, a);
		} else if (n == 2) {
			cin >> u >> v >> a;
			s = (v*v - u*u)/(2*a);
			t = (v - u)/a;
			printf("Case %d: %.3lf %.3lf\n", tc, s, t);
		} else if (n == 3) {
			cin >> u >> a >> s;
			v = sqrtl(u*u+2*a*s);
			t = (v - u)/a;
			printf("Case %d: %.3lf %.3lf\n", tc, v, t);
		} else if (n == 4) {
			cin >> v >> a >> s;
			u = sqrtl(v*v - 2*a*s);
			t = (v - u)/a;
			printf("Case %d: %.3lf %.3lf\n", tc, u, t);
		}
	}
	return 0;
}
