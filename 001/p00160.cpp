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

bool isPrime(int n) {
	if (n == 1) return false;
	f(i, 2, sqrt(n) + 1, 1) if (!(n%i)) return false;
	return true;
}

int main() {
	vi pr;
	f(i, 2, 100, 1) if (isPrime(i)) pr.pb(i);
	int n;
	while (cin >> n && n) {
		vi mul;
		f(i, 0, pr.size(), 1) {
			int l = pr[i], m = 1, k, ctr = 0;
			if (l > n) break;
			while (l*m <= n) { 
				k = l*m;
				while (!(k%l)) {k/=l; ++ctr;}
				++m;
			}
			mul.pb(ctr);
		}
		printf("%3d! =", n);
		f(i, 0, mul.size(), 1) {
			printf("%3d", mul[i]);
			if (i + 1 != (int)mul.size() && !((i + 1)%15)) cout << "\n      ";
		}
		cout << "\n";
	}
	return 0;
}
