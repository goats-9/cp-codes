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

int main() {
    int n; cin >> n;
    vvi adj(n, vi(n)), tadj(n, vi(n));
    vi v(n);
    f(i, 0, n, 1) f(j, 0, n, 1) cin >> tadj[i][j];
    f(i, 0, n, 1) {cin >> v[i]; --v[i]; } 
    reverse(all(v));
    f(i, 0, n, 1) f(j, 0, n, 1) adj[i][j] = tadj[v[i]][v[j]];
    vll ans_vec;
    f(k, 0, n, 1) { 
        f(i, 0, n, 1) { 
            f(j, 0, n, 1) { 
                if (adj[i][k] + adj[k][j] < adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
        ll ans = 0;
        f(i, 0, k + 1, 1) f(j, 0, k + 1, 1) ans += adj[i][j];
        ans_vec.pb(ans);
    }
    reverse(all(ans_vec));
    for (ll x : ans_vec) cout << x << " ";
    cout << nl;
	return 0;
}
