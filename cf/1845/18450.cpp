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
        int n, k, x;
        cin >> n >> k >> x;
        if (k == 1) cout << "NO\n";
        else if (k == 2) {
            if (x == 1) {
                if (n&1) cout << "NO\n";
                else {
                    cout << "YES\n" << (n>>1) << nl;
                    f(i,0,(n>>1),1) cout << "2 ";
                    cout << nl;
                }
            } else {
                cout << "YES\n" << n << nl;
                f(i,0,n,1) cout << "1 ";
                cout << nl;
            }
        } else {
            if (x == 1) {
                cout << "YES\n" << (n>>1) << nl;
                f(i,0,(n>>1)-1,1) cout << "2 ";
                if (n&1) cout << 3 << nl;
                else cout << 2 << nl;
            } else {
                cout << "YES\n" << n << nl;
                f(i,0,n,1) cout << "1 ";
                cout << nl; 
            }
        }
	}
	return 0;
}
