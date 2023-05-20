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
#define INF 1e9

vvi a, wp, vis;
int n, m, wpx, wpy;

bool good(int x) {
    vis.assign(n, vi(m, 0));
    queue<pii> q; q.push({wpx, wpy});
    vis[wpx][wpy] = 1;
    while (!q.empty()) {
        auto &[u, v] = q.front(); q.pop();
        if (u > 0 && abs(a[u][v] - a[u-1][v]) <= x && !vis[u-1][v]) {
            q.push({u-1,v});
            vis[u-1][v] = 1;
        }
        if (u < n - 1 && abs(a[u][v] - a[u+1][v]) <= x && !vis[u+1][v]) {
            q.push({u+1,v});
            vis[u+1][v] = 1;
        }
        if (v > 0 && abs(a[u][v] - a[u][v-1]) <= x && !vis[u][v-1]) {
            q.push({u,v-1});
            vis[u][v-1] = 1;
        }
        if (v < m - 1 && abs(a[u][v] - a[u][v+1]) <= x && !vis[u][v+1]) {
            q.push({u,v+1});
            vis[u][v+1] = 1;
        }
    }
    f(i,0,n,1) f(j,0,m,1) if (wp[i][j] && !vis[i][j]) return false;
    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    a.assign(n, vi(m, 0)), wp.assign(n, vi(m, 0));
    f(i,0,n,1) f(j,0,m,1) cin >> a[i][j];
    f(i,0,n,1) f(j,0,m,1) {
        cin >> wp[i][j];
        if (wp[i][j]) wpx = i, wpy = j;
    }
    int l = -1, r = INF;
    while (r > l + 1) {
        int g = (l + r) / 2;
        if (good(g)) r = g;
        else l = g;
    }
    cout << r << nl;
	return 0;
}
