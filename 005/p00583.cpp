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

bool isPrime(int n) { 
	f(i, 2, sqrt(n) + 1, 1) if (!(n%i)) return false;
	return true;
}

vi ans;

void pf(int n) { 
	int i = 2, fac = 0;
	while (i <= sqrt(n)) { 
		if (!(n%i) && isPrime(i)) {fac = i; break;}
		++i;
	} 
	if (fac == 0) ans.pb(n);
	else {ans.pb(fac); pf(n/fac);}
}

int main() {
	int n;
    while (cin >> n && n) { 
		ans.clear();
		if (n < 0) ans.pb(-1);
		pf(abs(n));
		cout << n << " = " << ans[0];
		f(i, 1, ans.size(), 1) printf(" x %d", ans[i]);
		cout << nl;
	}
	return 0;
}
