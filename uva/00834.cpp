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
	ll n, d;
	while (cin >> n >> d) {
		vll a;
		if (n < d) {
			swap(n, d);
			a.pb(0);
		} else if (n == d) {
			cout << "[1]\n"; 
			continue;
		} 
		ll r = n%d, q = n/d;
		a.pb(q);
		while(r) {
			n = d, d = r;
			r = n%d, q = n/d;
			a.pb(q);
		}
		int sz = a.size();
		f(i,0,sz,1) {
			if (i == 0) cout << '[';
			else if (i == 1) cout << ';';
			else cout << ',';
			cout << a[i];
		}
		cout << "]\n";
	}
	return 0;
}
