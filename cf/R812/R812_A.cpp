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

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> n;
		int cx, cy, xl = 0, xr = 0, yl = 0, yr = 0;
		f(i, 0, n, 1) { 
			cin >> cx >> cy;
			if (cx) { 
				if (xl > cx) xl = cx;
				if (xr < cx) xr = cx;
			} else { 
				if (yl > cy) yl = cy;
				if (yr < cy) yr = cy;
			}
		}
		cout << 2*(xr + yr - xl - yl) << nl;
	}
	return 0;
}
