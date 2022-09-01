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
	int n; cin >> n;
	vll a(n);
	vll rem(n);
	f(i, 0, n, 1) { 
		cin >> a[i];
		if (i) a[i] += a[i - 1];
		rem[((a[i]%n) + n)%n]++;
	}
	ll ans = 0;
	f(i, 0, n, 1) ans += rem[i]*(rem[i] - 1)/2;
	cout << ans + rem[0] << nl;
	return 0;
}
