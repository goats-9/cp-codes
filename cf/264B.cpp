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
#define MOD (int)1e9 + 7
#define N (int)1e5

int main() {
    int n; cin >> n;
    vi a(n), dp(n, 1), fc(N + 1, -1);
    f(i, 0, n, 1) cin >> a[i];
    f(i, 0, n, 1) { 
        if (a[i] == 1) continue;
        for (int j = 1; j*j <= a[i]; j++) { 
            if (a[i]%j == 0) {
                dp[i] = max(dp[i], 1 + fc[j]);
                dp[i] = max(dp[i], 1 + fc[a[i]/j]);
            }
        }
        for (int j = 1; j*j <= a[i]; j++) { 
            if (a[i]%j == 0) {
                if (j > 1) fc[j] = max(fc[j], dp[i]);
                if (a[i]/j > 1) fc[a[i]/j] = max(fc[a[i]/j], dp[i]);
            }
        }
    }
    sort(all(dp)); cout << dp.back() << nl;
}
