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
	ll n, m;
    cin >> n >> m;
    vvll padj(n, vll());
    f(i,0,m,1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        padj[v].pb(u);
    }
    vvll dp((1<<n), vll(n, 0));
    dp[1][0] = 1;
    f(bm,2,(1<<n),1) {
        if (!(bm & (1<<0))) continue;
        if ((bm & (1<<(n-1))) && bm != (1<<n) - 1) continue;
        f(j,0,n,1) {
            if (!(bm & (1<<j))) continue;
            int pbm = bm ^ (1 << j);
            for (int u : padj[j]) {
                if (bm & (1 << u)) dp[bm][j] = (dp[bm][j] + dp[pbm][u]) % MOD1;
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << nl;
	return 0;
}
