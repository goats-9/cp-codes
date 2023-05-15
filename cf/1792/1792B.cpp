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
#define MOD (int)1e9 + 7

int main() {
	int t, a1, a2, a3, a4;
    cin >> t;
    while (t--) { 
        cin >> a1 >> a2 >> a3 >> a4;
        int mn = min(a2, a3), mx = max(a2, a3);
        int sm = max(a1 + mn - mx, 0);
        int rm = max(mx - mn - a1, 0) + a4;
        //cout << mn << ' ' << mx << ' ' << sm << ' ' << rm << nl;
        if (a1) cout << a1 + mn + min(a1 + mn, mx) + min(sm + 1, rm) << nl;
        else { 
            if (a2 || a3 || a4) cout << 1 << nl;
            else cout << 0 << nl;
        }
	}
	return 0;
}
