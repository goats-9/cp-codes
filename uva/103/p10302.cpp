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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7

ll ans[50005];

int main() {
	ans[1] = 1LL;
	f(i, 2, 50001, 1) { 
		ll k = i;
		ans[i] = ans[i - 1] + k*k*k;
	}
	int n;
	while (cin >> n) cout << ans[n] << "\n"; 
	return 0;
}
