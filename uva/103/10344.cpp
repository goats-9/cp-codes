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

int op(int x, int y, int code) {
	switch (code) {
		case 1: return x + y;
		case 2: return x - y;
		case 3: return x*y;
		default: return 0;
	}
}

int solve(vi &a) {
	f(o1,1,4,1) {
		f(o2,1,4,1) {
			f(o3,1,4,1) {
				f(o4,1,4,1) {
					int sm = op(a[0], a[1], o1);	
					sm = op(sm, a[2], o2);	
					sm = op(sm, a[3], o3);	
					sm = op(sm, a[4], o4);
					if (sm == 23) return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	vi a(5);
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] && a[0]) {
		int fl = 0;
		sort(all(a));
		do if (solve(a)) {fl = true; break;}
		while (next_permutation(all(a)));
		if (fl) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}
