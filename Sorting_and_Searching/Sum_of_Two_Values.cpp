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
	V<pii> a(n);
	f(i, 0, n, 1) { cin >> a[i].first; a[i].second = i + 1; }
	int fl = 0;
	sort(all(a));
	vi b;
	f(i, 0, n, 1) b.pb(a[i].first);
	f(i, 0, n, 1) { 
		int pos = upper_bound(all(b), x - b[i]) - 1 - b.begin();
		if (pos >= 0 && i >= 0 && pos != i && b[pos] + b[i] == x) { 
			int x = min(a[i].second, a[pos].second), y = max(a[i].second, a[pos].second);
			cout << x << " " << y << nl;
			fl = 1;
			break;
		}
	}
	if (!fl) cout << "IMPOSSIBLE\n"; 
	return 0;
}
