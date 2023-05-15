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

vi coin = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll memo[30010][11];

ll dp(int i, int j) { 
	if (i < 0 || j == 11) return 0;
	if (i == 0) return 1;
	ll &ans = memo[i][j];
	if (ans != -1) return ans;
	return ans = dp(i, j + 1) + dp(i - coin[j], j);
}
int main() {
	string s;
    while (cin >> s && s != "0.00") { 
		reset(memo, -1);
		int i = 0, n = s.size(), x = 0;
		while (i < n) {
			if (s[i] != '.') x = 10*x + (s[i] - '0');
			++i;
		}
		printf("%6s%17lld\n", s.c_str(), dp(x, 0));
	}
	return 0;
}
