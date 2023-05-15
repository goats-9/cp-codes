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

int main() {
	int n, m;
    while (cin >> n >> m) {
		if (n <=  1 || m <= 1) { 
			cout << "Boring!\n";
			continue;
		}
		vi a;
		int fl = 0;
		a.pb(n);
		while (n != 1) { 
			if (n%m) {fl = 1; break;}
			else { 
				a.pb(n/m);
				n /= m;
			}
		}
		if (fl) cout << "Boring!\n";
		else { 
			int sz = a.size();
			f(i, 0, sz, 1) { 
				cout << a[i];
				if (i != sz - 1) cout << " ";
				else cout << "\n";
			}
		}
	}
	return 0;
}
