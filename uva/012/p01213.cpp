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

vi pr;
int N, memo[1150][16][1150];

bool isPrime(int i) { 
	if (i < 2) return false;
	f(j, 2, sqrt(i) + 1, 1) if (!(i%j)) return false;
	return true;
}

int dp(int id, int n, int k) { 
	if (n == 0 && k == 0) return 1;
	else if (n <= 0 || k == 0 || id == N) return 0;
	int &ans = memo[n][k][id];
	if (ans != -1) return ans;
	return ans = dp(id + 1, n - pr[id], k - 1) + dp(id + 1, n, k);
}

int main() {
	f(i, 2, 1120, 1) { 
		if (isPrime(i)) pr.pb(i);
	}
	N = pr.size();
	int n, k;
	reset(memo, -1);
    while (cin >> n >> k && n) { 
		cout << dp(0, n, k) << nl;
	}
	return 0;
}
