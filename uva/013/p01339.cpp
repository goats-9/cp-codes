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

int a[26], b[26], fa[101], fb[101];

bool cmp() { 
	f(i, 0, 101, 1) if (fa[i] != fb[i]) return false;
	return true;
}

int main() {
	string c, p;
    while (cin >> c >> p) { 
		reset(a, 0), reset(b, 0), reset(fa, 0), reset(fb, 0);
		f(i, 0, c.size(), 1) ++a[c[i] - 'A'];
		f(i, 0, p.size(), 1) ++b[p[i] - 'A'];
		f(i, 0, 26, 1) ++fa[a[i]];
		f(i, 0, 26, 1) ++fb[b[i]];
		if (cmp()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
