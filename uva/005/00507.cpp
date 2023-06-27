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
#define INF 2e18;

int main() {
	int b;
	cin >> b;
	f(tc,1,b+1,1) {
		int n;
		cin >> n;
		ll best = 0, cur = 0;
		int l = MOD1, r = 0, st = 1;
		f(i,2,n+1,1) {
			ll x;
			cin >> x;
			cur += x;
			if (cur < 0) cur = 0, st = i;
			if (cur >= best) { 
				if (cur > best || (cur == best && (i - st > r - l))) {
					l = st, r = i;
				}
				best = cur;
			}
		}
		if (best > 0) cout << "The nicest part of route " << tc << " is between stops " << l << " and " << r << nl;
		else cout << "Route " << tc << " has no nice parts\n";
	}
	return 0;
}
