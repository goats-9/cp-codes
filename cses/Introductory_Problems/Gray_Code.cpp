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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	string s(16, '0');
	V<string> gc;
	gc.pb(s);
	s[15] = '1';
	gc.pb(s);
	f(i, 1, 16, 1) f(j, 0, 1 << i, 1) {
		string p = gc[(1 << i) - j - 1];
		p[15 - i] = '1';
		gc.pb(p);
	}
	int n;
    scanf("%d", &n);
	f(i, 0, (1 << n), 1) cout << gc[i].substr(16 - n, n) << nl;
	return 0;
}
