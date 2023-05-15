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
#define MOD (ll)1e9 + 7
#define N (int)1e5

int main() {
	int t, k, x, y; cin >> t >> k;
    vll a(N + 1); a[1] = 1, a[k] += 1;
    f(i, 1, N + 1, 1) {
        a[i] += a[i - 1] + ((i < k) ? 0 : a[i - k]);
        a[i] %= MOD;
    }
    f(i, 1, N + 1, 1) { 
        a[i] += a[i - 1];
        a[i] %= MOD;
    }
    f(i, 0, t, 1) { 
        cin >> x >> y;
        ll ans = a[y] - a[x - 1];
        if (ans < 0) ans += MOD;
        ans %= MOD;
        cout << ans << nl;
    }
    return 0;
}