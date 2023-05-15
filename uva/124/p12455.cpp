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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int t, l, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> l >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int ans, fl = 0;
		f(i, 0, (1<<n), 1) { 
			ans = 0;
			f(j, 0, n, 1) if (i & (1 << j)) ans += a[j];
			if (ans == l) {fl = 1; break;}
		}
		if (!fl) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
