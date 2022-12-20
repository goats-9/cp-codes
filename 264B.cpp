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
    V<bool> s(N + 1, true);
    vi fc(N + 1);
    f(i, 4, N + 1, 2) s[i] = false;
    f(i, 3, N + 1, 1) f(j, i*i, N + 1, i) s[j] = false;
    vi a(n), dp(n, 1);
    f(i, 0, n, 1) cin >> a[i];
    f(i, 0, n, 1) {
        for (int j = 2; j*j <= a[i]; j++) {
            if (!(a[i]%j) && s[j]) {
                dp[i] = max(dp[fc[j]] + 1, dp[i]);
                fc[j] = max(fc[j], i);
            }
        }
    }
    sort(all(dp)); 
    cout << dp.back() << nl;
	return 0;
}
