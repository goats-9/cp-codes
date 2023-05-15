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
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        vvi a(2, vi(n));
        a[0][0] = 2*n;
        a[1][0] = 1;
        int ctr = 2;
        f(i,1,n,1) {
            if (i%2) {
                a[0][i] = ctr;
                a[1][i] = ctr + n - 1;
            } else {
                a[0][i] = ctr + n - 1;
                a[1][i] = ctr;
            }
            ++ctr;
        }
        f(i,0,2,1) {
            f(j,0,n,1) cout << a[i][j] << ' ';
            cout << nl;
        }
	}
	return 0;
}
