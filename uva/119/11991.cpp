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
#define N 1000001

int main() {
	int n, m;
	while (cin >> n >> m) {
		M<int, vi> a;
		f(i,0,n,1) {
			int x;
			cin >> x;
			a[x].pb(i+1);
		}
		f(i,0,m,1) {
			int p, q;
			cin >> p >> q;
			if (a.find(q) == a.end() || ((int)a[q].size() < p)) cout << 0 << nl;
			else cout << a[q][p-1] << nl;
		}
	}
	return 0;
}
