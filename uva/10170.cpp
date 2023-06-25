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
#define INF (ll)1e9

int main() {
	ll s, d;
	while (cin >> s >> d) { 
		if (d <= s) {cout << s << nl; continue;}
		ll l = s, r = INF;
		while (r - l > 1) {
			ll g = (r+l)/2;
			ll k = ((g+s)*(g-s+1))/2;
			if (k < d) l = g;
			else r = g;
		}
		cout << r << nl;
	}
	return 0;
}
