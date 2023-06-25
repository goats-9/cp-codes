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
	int k, tc = 0;
	while (cin >> k && k != -1) {
		if (tc++) cout << nl;
		vi a;
		a.pb(-k);
		while (cin >> k && k != -1) a.pb(-k);
		vi lis;
		for (auto u : a) {
			int pos = lower_bound(all(lis), u) - lis.begin();
			if (pos == (int)lis.size()) lis.pb(u);
			else lis[pos] = u;
		}
		cout << "Test #" << tc << ":\n  maximum possible interceptions: " << lis.size() << nl; 
	}
	return 0;
}
