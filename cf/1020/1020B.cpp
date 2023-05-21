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
    int n;
    cin >> n;
    vi a(n+1), ans(n+1);
    f(i,1,n+1,1) cin >> a[i];
    V<bool> vis(n+1, false);
    f(i,1,n+1,1) {
        if (vis[i]) continue;
        int u = i;
        while (!vis[u]) vis[u] = true, u = a[u];
        int v = i;
        if (ans[u]) {
            while (v != u) ans[v] = ans[u], v = a[v];
        } else {
            ans[u] = u;
            while (v != u) ans[v] = u, v = a[v];
            v = a[u];
            while (v != u && !ans[v]) ans[v] = v, v = a[v];
        }
    }
    f(i,1,n+1,1) cout << ans[i] << ' ';
    cout << nl;
	return 0;
}
