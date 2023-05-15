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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (ll)1000000007
#define N 2000
#define K 2000

int main() {
    int n, k; 
    cin >> n >> k;
    vvll dp(N + 1, vll(K + 1, 0));
    f(i, 1, N + 1, 1) dp[i][1] = 1;
    f(j, 1, K + 1, 1) dp[1][j] = 1;
    f(i, 2, N + 1, 1) { 
        vi fac;
        for (int k = 1; k*k <= i; k++) { 
            if (!(i%k)) { 
                fac.pb(k);
                if (k*k != i) fac.pb(i/k);
            }
        }
        f(j, 2, K + 1, 1) for (int x : fac) (dp[i][j] += dp[x][j - 1])%=MOD;
    }
    f(j, 1, K + 1, 1) f(i, 2, N + 1, 1) (dp[i][j] += dp[i - 1][j])%=MOD;
    cout << dp[n][k];
    return 0;
}