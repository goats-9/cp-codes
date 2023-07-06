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

int sumDigits(int n) {
	int ans = 0;
	while (n) ans += (n%10), n /= 10;
	return ans;
}

bool isPrime(int n) {
	for (int i = 2; i*i <= n; i++) if (!(n%i)) return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) { 
		int st;
		cin >> st;
		int n = st + 1;
		while (1) {
			if (isPrime(n)) {
				n++;
				continue;
			}
			int smd = sumDigits(n);
			int smp = 0;
			int m = n;
			for (int i = 2; i*i <= m; i++) {
				if (m%i) continue;
				while (m%i == 0) smp += sumDigits(i), m /= i;
			}
			if (m>1) smp += sumDigits(m);
			if (smp == smd) {cout << n << nl; break;}
			n++;
		}
	}
	return 0;
}
