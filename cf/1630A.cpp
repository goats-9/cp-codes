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
	int t, n, k;
	cin >> t;
    while (t--) { 
        cin >> n >> k;
        if (k == n - 1) {
            if (k == 3) cout << -1 << nl;
            else {
                cout << n - 1 << ' ' << n - 2 << nl;
                cout << 1 << ' ' << (n>>1)-1 << nl;
                cout << 0 << ' ' << (n>>1) << nl;
                f(i,2,(n>>1)-1,1) cout << i << ' ' << n - 1 - i << nl; 
            }
            continue;
        }
        if (k == 0) {
            f(i,0,n>>1,1) cout << i << ' ' << n - i - 1 << nl;
            continue;
        }
        cout << k << ' ' << n - 1 << nl;
        cout << n - 1 - k << ' ' << 0 << nl;
        if (k >= n>>1) {
            f(i,n>>1,n-1,1) if (i!=k) cout << i << ' ' << n - 1 - i << nl;
        } else {
            f(i,1,n>>1,1) if (i!=k) cout << i << ' ' << n - 1 - i << nl;
        }
	}
	return 0;
}
