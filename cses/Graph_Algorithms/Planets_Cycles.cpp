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
    vi a(n+1), vis(n+1), ans(n+1);
    f(i,1,n+1,1) cin >> a[i];
    f(i,1,n+1,1) {
        if (vis[i]) continue;
        int unvis = 0;
        int u = i;
        while (!vis[u]) {
            vis[u] = true;
            u = a[u];
            ++unvis;
        }
        int v = i;
        if (!ans[u]) {
            while (v != u) ans[v] = unvis--, v = a[v];
            ans[u] = unvis;
            v = a[u];
            while (v != u) ans[v] = unvis, v = a[v];
        } else while (v != u) ans[v] = ans[u] + unvis--, v = a[v];
    }
    f(i,1,n+1,1) cout << ans[i] << ' ';
    cout << nl;
	return 0;
}
