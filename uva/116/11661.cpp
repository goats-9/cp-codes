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
#define INF 1000000000

int main() {
	int n;
	string s;
	while (cin >> n && n) {
		cin >> s;
		vi r;
		r.pb(-INF);
		bool fl = false;
		f(i,0,n,1) {
			char ch = s[i];
			if (ch == 'Z') {fl = true; break;}
			else if (ch == 'R') r.pb(i);
		}
		r.pb(INF);
		if (fl) {cout << 0 << nl; continue;}
		int ans = INF;
		f(i,0,n,1) {
			if (s[i] == 'D') {
				int pos = lower_bound(all(r), i) - r.begin();
				ans = min(ans, min(abs(i-r[pos]), abs(i-r[pos-1])));
			}
		}
		cout << ans << nl;
	}
	return 0;
}
