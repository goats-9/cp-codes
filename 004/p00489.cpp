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

int a[26], b[26];

int main() {
	int n;
	string s, g;
    while (cin >> n && n != -1) { 
		cin >> s >> g;
		cout << "Round " << n << nl; 
		int wg = 0, fl = 0, cg = 0, ng = 0;
		reset(a, 0), reset(b, 0);
		f(i, 0, s.size(), 1) if (!a[s[i] - 'a']) {a[s[i] - 'a'] = 1; ++ng;}
		f(i, 0, g.size(), 1) { 
			if (!b[g[i] - 'a']) { 
				b[g[i] - 'a'] = 1;
				if (a[g[i] - 'a']) ++cg;
				else ++wg;
			}
			if (wg == 7) {fl = 1; break;}
			else if (cg == ng) {fl = 2; break;}
		}
		if (fl == 1) cout << "You lose.\n";
		else if (fl == 2) cout << "You win.\n";
		else cout << "You chickened out.\n";
	}
	return 0;
}
