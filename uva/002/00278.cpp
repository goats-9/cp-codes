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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	int t;
	cin >> t;
	while (t--) { 
		char ch;
		int m, n;
		cin >> ch >> m >> n;
		if (ch == 'r' || ch == 'Q') cout << min(m,n) << nl;
		else if (ch == 'k') cout << ((m*n)>>1) + ((m*n)&1) << nl;
		else if (ch == 'K') cout << ((m>>1)+(m&1))*((n>>1)+(n&1)) << nl;
	}
	return 0;
}
