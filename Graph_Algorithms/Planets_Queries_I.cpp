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
#define LSOne(s) (s & (-s))

int main() {
	int n, q, u, k;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	vvi a(32, vi(n+1));
	f(i,1,n+1,1) cin >> a[0][i];
	f(i,1,31,1) f(j,1,n+1,1) a[i][j] = a[i-1][a[i-1][j]];
	f(i,0,q,1) {
		cin >> u >> k;
		int v = u;
		while (k) {
			v = a[log2(LSOne(k))][v];
			k -= LSOne(k);
		}
		cout << v << nl;
	}
	return 0;
}
