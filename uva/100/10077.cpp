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
	ll n, d;
	while (cin >> n >> d) {
		if ((n == 1) && (d == 1)) break;
		ll ln = 0, ld = 1, rn = 1, rd = 0;
		ll cn, cd;
		while (1) {
			cn = ln+rn, cd = ld+rd;
			ll x = n*cd - cn*d;
			if (x < 0) {
				cout << 'L';
				rn = cn, rd = cd;
			} else if (x > 0) {
				cout << 'R';
				ln = cn, ld = cd;
			} else break;
		}
		cout << nl;
	}
	return 0;
}
