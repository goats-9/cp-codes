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

ll Pow(ll x, ll y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}

int main() {
	string s;
	int x;
    while (getline(cin, s)) { 
		int fl = 0, xs = s.size();
		x = 0;
		f(i, 0, xs, 1) {
			if (s[i] == '-') fl = 1;
			else x = 10*x + (s[i] - '0');
		}
		if (fl) x = -x;
		vi a;
		int c = 0;
		getline(cin, s);
		int sz = s.size(), i = 0;
		while (i < sz) { 
			fl = 0;
			c = 0;
			while (i < sz && s[i] != ' ') { 
				if (s[i] == '-') fl = 1;
				else c = 10*c + (s[i] - '0');
				++i;
			}
			if (fl) c = -c;
			a.pb(c);
			++i;
		}
		sz = a.size();
		ll ans = 0;
		f(i, 0, sz - 1, 1) ans += ll(sz - i - 1)*ll(a[i])*ll(Pow(x, sz - i - 2));
		cout << ans << nl;
	}
	return 0;
}
