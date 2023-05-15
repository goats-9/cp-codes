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
    int n, m, x, y; cin >> n >> m;
    vvi adj(n + 1, vi());
    vvi pth(n + 1, vi(n + 1, 0));
    f(i, 0, m, 1) {
        cin >> x >> y;
        adj[x].pb(y);
    }
    f(i, 1, n + 1, 1) { 
        f(j, 0, adj[i].size(), 1) { 
            int v = adj[i][j];
            f(k, 0, adj[v].size(), 1) { 
                int w = adj[v][k];
                if (i != w) ++pth[i][w];
            }
        }
    }
    ll ans = 0;
    f(i, 1, n + 1, 1) { 
        f(j, 1, n + 1, 1) { 
            ll p = pth[i][j];
            ans += p*(p - 1)/2;
        }
    }
    cout << ans << nl;
	return 0;
}
