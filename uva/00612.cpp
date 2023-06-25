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
	int t;
	cin >> t;
	f(k,0,t,1) {
		if (k) cout << nl;
		int n, m;
		cin >> n >> m;
		V<string> a(m);
		V<pii> srt(m);
		f(i,0,m,1) {
			cin >> a[i];
			string s = a[i];
			int inv = 0;
			f(p,0,n,1) f(q,p+1,n,1) inv += (s[p] > s[q]);
			srt[i] = mp(inv, i);
		}
		sort(all(srt));
		for (auto &[_, u]: srt) cout << a[u] << nl;
	}
	return 0;
}
