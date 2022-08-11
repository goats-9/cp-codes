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

int memo[27][352][27];

int dp(int l, int s, int idx) { 
	if (s < 0) return 0;
	if (l == 0) return s ? 0 : 1;
	if (idx > 26) return 0;
	int &ans = memo[l][s][idx];
	if (ans != -1) return ans;
	ans = 0;
	f(i, idx, 27, 1) ans += dp(l - 1, s - i, i + 1);
	return ans;
}

int main() {
	int tc = 0, l, s;
	reset(memo, -1);
    while (cin >> l >> s && l) {
		cout << "Case " << ++tc << ": ";
		if (l < 27 && s < 352) cout << dp(l, s, 1) << nl;
		else cout << "0\n";
	}
	return 0;
}
