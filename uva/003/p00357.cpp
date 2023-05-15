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

ll memo[30010][5];
vi denom = {1, 5, 10, 25, 50};

ll dp(int u, int d) { 
	if (u < 0) return 0;
	if (u == 0) return 1;
	ll &ans = memo[u][d];
	if (ans != -1) return ans;
	ans = 0;
	f(i, d, 5, 1) ans += dp(u - denom[i], i); 
	return ans;
}

int main() {
	int n;
	reset(memo, -1LL);
	while (cin >> n) { 
		ll a = dp(n, 0);
		if (a == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
		else cout << "There are " << a <<  " ways to produce " << n << " cents change.\n";
	}
	return 0;
}
