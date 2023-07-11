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
        int n;
        cin >> n;
        vvi a(n, vi(26, 1));
        vi fac;
        fac.pb(1);
        for (int i = 2; i*i <= n; i++) {
            if (n%i) continue;
            fac.pb(i);
            if (i*i != n) fac.pb(n/i);
        }
        f(i,0,n,1) {
            int pos = -1;
            f(j,0,26,1) if (a[i][j]) {
                cout << char('a'+j);
                pos = j;
                break;
            }
            for (auto x : fac) if (i + x < n) a[i+x][pos] = 0;
        }
        cout << nl;
	}
	return 0;
}
