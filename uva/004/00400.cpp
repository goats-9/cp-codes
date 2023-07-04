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
	string s(60, '-');
	int n;
	while (cin >> n && n) {
		cout << s << nl;
		int mx = 0;
		V<string> a;
		f(i,0,n,1) {
			string t;
			cin >> t;
			a.pb(t);
			mx = max(mx, (int)t.size());
		}
		sort(all(a));
		int col = 62/(mx+2);
		int row = n/col + (n%col != 0);
		vvi lst(row, vi(col, -1));
		f(i,0,n,1) {
			int cl = i/row;
			int rw = i%row;
			lst[rw][cl] = i;
		}
		f(i,0,row,1) {
			f(j,0,lst[i].size(),1) {
				if (lst[i][j] == -1) continue;
				string p = a[lst[i][j]];
				if (j + 1 == col) cout << setw(mx) << left << p;
				else cout << setw(mx + 2) << left << p;
			}
			cout << nl;
		}
	}
	return 0;
}
