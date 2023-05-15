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
	scanf("%d", &n);
	vi a(n), b(n);
	f(i, 0, n, 1) { scanf("%d", &a[i]); b[a[i] - 1] = i; }
	int ans = 0, i = 0;
	while (i < n) { 
		int k = 0;
		while (i + k + 1 < n && b[i + k + 1] > b[i + k]) ++k;
		i += (k + 1);
		++ans;
	}
	cout << ans << nl;
	return 0;
}
