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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, b, sizeof(a))
#define MOD (int)1e9 + 7
#define INF (int)1e9

ll memo[32], cost[32];
int n;

ll dp(ll sm, int u) { 
	if (sm < 0) return INF;
	if (u == n) return sm;
	ll &ans = memo[u];
	return ans = min(dp(sm, u + 1), dp(sm - cost[u], u + 1));
}

int main() {
	reset(memo, -1LL);
	ll sm = 0;
	cin >> n;
	f(i, 0, n, 1) {
		cin >> cost[i];
		sm += cost[i];
	}
	ll ret = dp(sm/2, 0);
	if (sm%2) cout << 2*ret + 1 << nl;
	else cout << 2*ret << nl;
	return 0;
}
