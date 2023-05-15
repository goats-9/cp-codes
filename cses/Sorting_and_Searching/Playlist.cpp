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
	int n;
	cin >> n;
	vi a(n);
	mii idxmp;
	f(i, 0, n, 1) cin >> a[i];
	int ans = 0, l = 0, r = 0;
	f(i, 0, n, 1) { 
		if (idxmp.find(a[i]) == idxmp.end() || idxmp[a[i]] < l) idxmp[a[i]] = i, r = i;
		else l = idxmp[a[i]] + 1, idxmp[a[i]] = i;
		ans = max(ans, r + 1 - l);
	}
	cout << ans << nl;
	return 0;
}