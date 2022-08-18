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
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int n, memo[1050];
vi a;

int dp(int u) { 
	int &ans = memo[u];
	if (ans != -1) return ans;
	ans = 1;
	for (int i = u - 1; i >= 0; i--) {
		if ((a[i]^u) < (a[u]^i)) ans = max(ans, 1 + dp(i));
	}
	return ans;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		reset(memo, -1);
		cin >> n;
		a.assign(n, 0);
		int ans = 0;
		f(i, 0, n, 1) cin >> a[i];
		for (int i = n - 1; i >= 0; i--) { 
			ans = max(ans, dp(min(n - 1, i)));
		}
		if (ans == 1) ans = 0;
		cout << ans << nl;
	}
	return 0;
}
