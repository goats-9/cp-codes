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
	while (t--) { 
        ll xa, xb, xc, ya, yb, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        ll bx = fabsl(xa - xb), by = fabsl(ya - yb), cx = fabsl(xa - xc), cy = fabsl(ya - yc);
        ll xcm = 0, ycm = 0;
        if ((xa < xb && xa < xc) || (xa > xb && xa > xc)) xcm = min(bx, cx);
        if ((ya < yb && ya < yc) || (ya > yb && ya > yc)) ycm = min(by, cy);
        cout << xcm + ycm + 1 << nl;
	}
	return 0;
}
