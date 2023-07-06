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
	while (cin >> n && n) {
		int ans = n;
		vi pr;
		for (int i = 2; i*i <= n; i++) {
			if (n%i) continue;
			pr.pb(i);
			while (n%i == 0) n /= i;
		}
		if (n > 1) pr.pb(n);
		for (auto p : pr) {
			ans /= p;
			ans *= (p - 1);
		}
		cout << ans << nl;
	}
	return 0;
}
