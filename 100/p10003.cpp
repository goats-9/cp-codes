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

int memo[64][64], a[64], l, n;

int dp(int i, int j) {
	int &ans = memo[i][j];
	if (ans != -1) return ans;
	if (j == 1) return ans = 0;
	ans = INT_MAX;
	f(k, 1, j, 1) ans = min(ans, (dp(i, k) + dp(i + k, j - k) + a[i + j] - a[i]));
	return ans;
}

int main() {
	while (cin >> l && l) { 
		cin >> n;
		reset(memo, -1), reset(a, 0);
		a[0] = 0, a[n + 1] = l;
		f(i, 1, n + 1, 1) cin >> a[i];
		cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";
	}
	return 0;
}
