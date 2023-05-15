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

int main() {
	ll ans[10000];
	ans[0] = 0;
	ans[1] = 6;
	ans[2] = 28;
	for (ll n = 4; n < 10001; n++) ans[n - 1] = (n*n*(n*n - 1) - 48 - 40*(n - 4) - 8*(n - 4)*(n - 4))/2;
	int x;
	cin >> x;
	f(i, 0, x, 1) cout << ans[i] << nl;
	return 0;
}
