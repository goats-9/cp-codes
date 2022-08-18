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
	int t, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int ans = 0, i = 0;
		while (i < n) {
			if (a[i] == 0) {++i; continue;}
			int k = 0;
			while (i + k < n && a[i] == a[i + k]) ++k;
			ans += (k/2 + k%2);
			if (i + k < n && k%2 && a[i + k]) a[i + k] ^= a[i];
			i += k;
		}
		cout << ans << nl;
	}
	return 0;
}
