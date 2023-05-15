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

vi a, b;
int memo[25][25];

int dp(int i, int j) { 
	int &ans = memo[i][j];
	if (i == 0 || j == 0) return ans = 0;
	if (ans != -1) return ans;
	if (a[i - 1] == b[j - 1]) return ans = 1 + dp(i - 1, j - 1);
	return ans = max(dp(i, j - 1), dp(i - 1, j));
}

int main() {
	int n, x;
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	f(i, 0, n, 1) { cin >> x; a[x - 1] = i + 1; }
	while (cin >> x) { 
		reset(memo, -1);
		b[x - 1] = 1;
		f(i, 1, n, 1) { cin >> x; b[x - 1] = i + 1; } 
		cout << dp(n, n) << "\n";
	}
	return 0;
}
