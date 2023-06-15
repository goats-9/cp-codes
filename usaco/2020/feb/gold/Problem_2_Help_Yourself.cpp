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
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n;
    cin >> n;
    vi a(2*n + 1, 0);
    f(i,0,n,1) {
        int x, y;
        cin >> x >> y;
        a[x]++, a[y]--;
    }
    vll pow2(n+1,1);
    f(i,1,n+1,1) pow2[i] = (2*pow2[i-1])%MOD1;
    int open = 0;
    ll ans = 0;
    f(i,1,2*n+1,1) {
        open += a[i];
        if (a[i] == 1) ans = (ans + pow2[n-open])%MOD1;
    }
    cout << ans << nl;
	return 0;
}
