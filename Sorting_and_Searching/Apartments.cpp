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
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	f(i, 0, n, 1) cin >> a[i];
	f(i, 0, m, 1) cin >> b[i];
	sort(all(a)); sort(all(b));
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) { 
		if (b[j] - k <= a[i] && a[i] <= b[j] + k) ++ans, ++j, ++i;
		else if (a[i] > b[j] + k) ++j;
		else ++i;
	}
	cout << ans << nl;
	return 0;
}
