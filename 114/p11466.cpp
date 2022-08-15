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

bool isPrime(ll n) { 
	f(i, 2, sqrt(n) + 1, 1) if (!(n%i)) return false;
	return true;
}

int main() {
	ll n;
    while (cin >> n && n) { 
		n = abs(n);
		if (n == 1 || isPrime(n)) cout << "-1\n";
		else { 
			ll ans = 0, ctr = 0;
			f(i, 2, sqrt(n) + 1, 1) { 
				if (!(n%i)) { 
					if (isPrime(i)) { 
						++ctr; ans = max(ans, ll(i));
					}
					if (i != n/i && isPrime(n/i)) { 
						++ctr; ans = max(ans, ll(n/i));
					}
				}
			}
			if (ctr > 1) cout << ans << nl;
			else cout << "-1\n";
		}
	}
	return 0;
}
