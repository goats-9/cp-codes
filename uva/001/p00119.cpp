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
	int n, m, p, tc = 0;
	string s;
    while (cin >> n) { 
		if (tc) cout << nl;
		tc++;
		V<string> names;
		M<string, int> worth;
		f(i, 0, n, 1) {
			cin >> s;
			names.pb(s);
			worth[s] = 0;
		}
		f(i, 0, n, 1) { 
			cin >> s >> m >> p;
			if (!p) continue;
			worth[s] -= p*(m/p);
			f(j, 0, p, 1) { 
				cin >> s;
				worth[s] += (m/p);
			}
		}
		f(i, 0, n, 1) cout << names[i] << " " << worth[names[i]] << nl;
	}
	return 0;
}
