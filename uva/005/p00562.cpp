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
#define INF (int)1e9

int s, n, memo[50001][100], coin[100];

int dp(int pr, int cn) { 
	if (cn == n) return abs(s - 2*pr); 
	int &ans = memo[pr][cn];
	if (ans != -1) return ans;
	return ans = min(dp(pr - coin[cn], cn + 1), dp(pr, cn + 1));
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		reset(memo, -1);
		cin >> n;
		s = 0;
		f(i, 0, n, 1) {cin >> coin[i]; s += coin[i];}
		cout << dp(s, 0) << nl;
	}
	return 0;
}
