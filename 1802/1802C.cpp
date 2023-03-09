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
    ll t, n, m;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        cout << n*m << nl;
        vvll a(n,vll(m));
        a[0][0] = 1LL<<60;
        f(i,1,m,2) {
            a[0][i] = a[0][i-1] + (1LL<<10);
            if (i + 1 < m) a[0][i+1] = a[0][i];
        }
        f(i,1,n,2) {
            f(j,0,m,1) {
                a[i][j] = a[i-1][j] + 1;
                if (i + 1 < n) a[i+1][j] = a[i][j];
            }
        }
        f(i,0,n,2) {
            f(j,0,m,2) {
                a[i][j] = (a[i][j]<<2) + 0;
                if (j + 1 < m) a[i][j+1] = (a[i][j+1]<<2) + 1;
                if (i + 1 < n) {
                    a[i+1][j] = (a[i+1][j]<<2) + 2;
                    if (j + 1 < m) a[i+1][j+1] = (a[i+1][j+1]<<2) + 3;
                }
            }
        }
        f(i,0,n,1) {
            f(j,0,m,1) cout << a[i][j] << ' ';
            cout << nl;
        }
	}
	return 0;
}
