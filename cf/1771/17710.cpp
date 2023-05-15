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
	ll t, n;
    cin >> t;
    while (t--) { 
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		sort(all(a));
		ll ans = 0;
		if (a[0] == a[n - 1]) { 
			ans = n*(n - 1);
		} else { 
			int k = 0, l = 0;
			while (a[0] == a[k]) k++;
			while (a[n - 1] == a[n - 1 - l]) l++;
			ans = 2*l*k;
		}
		cout << ans << nl;
	}
	return 0;
}
