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
	int n, x;
	cin >> n >> x;
	V<P<ll, int>> a(n);
	f(i, 0, n, 1) {
		cin >> a[i].first;
		if (i) a[i].first += a[i - 1].first;
		a[i].second = i;
	}
	sort(all(a));
	ll ctr = 0;
	f(i, 0, n, 1) { 
		int pos = lower_bound(all(a), mp(x + a[i].first, a[i].second + 1)) - a.begin();
		if (pos < n && a[pos].first - a[i].first == x) { 
			int up = upper_bound(all(a), mp(x + a[i].first, n)) - a.begin();
			ctr += (up - pos);
		}
	}
	int pos = lower_bound(all(a), mp(ll(x), 0)) - a.begin();
	if (a[pos].first == x) { 
		int up = upper_bound(all(a), mp(ll(x), n)) - a.begin();
		ctr += (up - pos);
	} 
	cout << ctr << nl;
	return 0;
}
