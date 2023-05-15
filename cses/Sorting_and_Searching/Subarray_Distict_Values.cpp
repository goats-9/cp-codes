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
	int n, k;
	cin >> n >> k;
	vi a(n);
	f(i, 0, n, 1) cin >> a[i];
	mii elem;
	set<int> ui;
	ll ans = 0;
	int l = 0, r = 0, ctr = 0;
	while (r < n) { 
		if (elem.find(a[r]) == elem.end()) ++ctr;
		else ui.erase(elem[a[r]]);
		elem[a[r]] = r;
		ui.insert(r);
		++r;
		if (ctr > k) { 
			--ctr;
			l = *(ui.upper_bound(l));
			cout << "update: " << l << nl;
		} else ans += (r - l);
	}
	cout << ans << nl;
	return 0;
}
