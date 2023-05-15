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
	vi a(n), fl(n);
	f(i, 0, n, 1) cin >> a[i];
	sort(all(a));
	int i = 0, j = n - 1;
	int ans = 0;
	while (i < j) { 
		if (a[i] + a[j] <= x) ++i;
		--j, ++ans;
	}
	if (i == j) ++ans;
	cout << ans << nl;
	return 0;
}
