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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	ll n, m;
	while (cin >> n >> m) {
		if (m == 0) {cout << m << " divides " << n << "!\n"; continue;}
		bool fl = true;
		ll tmp = m;
		mii fac;
		for (ll i = 2; i*i <= m; i++) {
			if (m%i) continue;
			ll pexp = 0;
			while (m%i == 0) ++pexp, m /= i;
			fac[i] = pexp;
		}
		if (m > 1) fac[m] = 1;
		for (auto &[pr, pexp] : fac) {
			ll p = 0, q = n;
			while (q) {q /= pr; p += q;}
			if (p < pexp) {fl = false; break;}
		}
		if (fl) cout << tmp << " divides " << n << "!\n";
		else cout << tmp << " does not divide " << n << "!\n";
	}
}
