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

int memo[1005][1005];
string a, b;

int dp(int i, int j) { 
	int &ans = memo[i][j];
	if (ans != -1) return ans;
	if (i == 0 || j == 0) return ans = 0;
	if (a[i - 1] == b[j - 1]) return ans = 1 + dp(i - 1, j - 1);
	else return ans = max(dp(i, j - 1), dp(i - 1, j));
}

int main() {
	while (getline(cin, a)) {
		getline(cin, b);
		reset(memo, -1);
		cout << dp(int(a.size()), int(b.size())) << "\n";
	}
	return 0;
}
