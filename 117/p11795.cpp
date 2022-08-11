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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int n, t;
ll memo[16][(1 << 16)], ctr;
string st;
int bot[16], gun;

ll tsp(int u, int mask) { 
	if (mask == 0) return 1LL;
	ll &ans = memo[u][mask];
	if (ans != -1) return ans;
	ans = 0;
	int og = gun;
	gun |= bot[u];
	f(i, 0, n, 1) if (mask & gun & (1 << i)) ans += tsp(i, mask^(1 << i));
	gun = og;
	return ans;
}

int main() {
	cin >> t;
    f(tc, 1, t + 1, 1) { 
		 cin >> n >> st;
		 reset(bot, 0);
		 gun = 0;
		 f(i, 0, n, 1) if (st[i] == '1') gun |= (1 << i);
		 ctr = 0;
		 f(i, 0, n, 1) {
			 cin >> st;
			 f(j, 0, n, 1) if (st[j] == '1') bot[i] |= (1 << j);
		 }
		 int mask = (1 << n) - 1;
		 f(i, 0, n, 1) {
			 reset(memo, -1LL);
			 if (gun & (1 << i)) ctr += tsp(i, mask^(1 << i));
		 }
		 cout << "Case " << tc << ": " << ctr << nl;
	}
	return 0;
}
