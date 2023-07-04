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

ll modexp(ll x, ll y, ll n) {
	if (y == 0) return 1;
	ll z = modexp(x, y/2, n);
	ll r = (z*z)%n;
	if (y&1) r = (r*x)%n;
	return r;
}

int main() {
	int t;
	cin >> t;
	while (t--) { 
		ll x, y, n;
		cin >> x >> y >> n;
		cout << modexp(x,y,n) << nl;
	}
	int eh;
	cin >> eh;
	return 0;
}
