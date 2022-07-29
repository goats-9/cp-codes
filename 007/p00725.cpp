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

int n;

bool isAll(int u) { 
	vi d(10);
	if (u < 10000) ++d[0];
	int p = u*n;
	if (p < 10000) ++d[0];
	while (u) { 
		++d[u%10];
		u/=10;
	}
	while (p) { 
		++d[p%10];
		p/=10;
	}
	f(i, 0, 10, 1) if (d[i] != 1) return false;
	return true;
}

void disp(int u) {printf("%05d / %05d = %d\n", u*n, u, n); }

int main() {
	int fl = 0;
	while (cin >> n && n) {
		if (fl) cout << "\n";
		fl = 1;
		vi sol;
		f(i, 1234, 50001, 1) { 
			if (i*n < 100000 && isAll(i)) sol.pb(i);
		}
		if (sol.size())	f(i, 0, sol.size(), 1) disp(sol[i]);
		else printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
