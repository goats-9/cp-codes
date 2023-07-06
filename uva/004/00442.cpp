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

int main() {
	int n;
	cin >> n;
	M<char, pll> dim;
	f(i,0,n,1) {
		char ch;
		ll x, y;
		cin >> ch >> x >> y;
		dim[ch] = {x, y};
	}
	string s;
	while (cin >> s) {
		ll ans = 0;
		stack<pii> stk;
		bool fl = true;
		for (char ch : s) {
			if (ch == '(') continue;
			else if (ch == ')') {
				pll m2 = stk.top(); stk.pop();
				pll m1 = stk.top(); stk.pop();
				if (m1.second != m2.first) {fl = false; break;}
				ans += m1.first*m2.first*m2.second;
				stk.push({m1.first,m2.second});
			} else stk.push(dim[ch]);
		}
		if (!fl) cout << "error\n";
		else cout << ans << nl;
	}
	return 0;
}
