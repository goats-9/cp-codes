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
#define MOD (int)1e8

int main() {
	int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int dp[n1 + 1][n2 + 1][2];
    reset(dp, 0);
    f(i, 1, min(n1, k1) + 1, 1) dp[i][0][0] = 1; 
    f(i, 1, min(n2, k2) + 1, 1) dp[0][i][1] = 1; 
    f(i, 1, n1 + 1, 1) { 
        f(j, 1, n2 + 1, 1) { 
            f(k, 1, min(n1, k1) + 1, 1) {
                if (i < k) break;
                dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1])%MOD;
            }            
            f(k, 1, min(n2, k2) + 1, 1) {
                if (j < k) break;
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0])%MOD;
            }            
        }
    }
    cout << (dp[n1][n2][1] + dp[n1][n2][0])%MOD << nl;
	return 0;
}
