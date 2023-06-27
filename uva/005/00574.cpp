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
	int t, n;
	while (cin >> t >> n && t) {
		vi a(n);
		V<string> st;
		f(i,0,n,1) cin >> a[i];
		for (int i = (1<<n)-1; i >= 0; i--) {
			int sm = 0;
			stringstream ss;
			for (int j = n - 1; j >= 0; j--) {
				if (i&(1<<j)) {
					sm += a[n-1-j];
					ss << a[n-1-j] << "+";
				}
			}
			string s = ss.str();
			s.pop_back();
			if ((sm == t) && (find(all(st), s) == st.end())) st.pb(s);
		}
		cout << "Sums of " << t << ":\n";
		if (st.size() == 0) cout << "NONE\n";
		else for (string s : st) cout << s << nl;
	}
	return 0;
}
