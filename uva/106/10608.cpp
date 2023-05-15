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
#define MOD (int)1e9 + 7
#define EPS 1e-7

V<bool> vis;
vvi adj;

int bfs(int u) {
    queue<int> q; q.push(u);
    int ctr = 0;
    vis[u] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop(); ++ctr;
        for (int y : adj[x]) {
            if (!vis[y]) {
                q.push(y);
                vis[y] = true;
            }
        }
    }
    return ctr;
}

int main() {
    int t, n, m, u, v; cin >> t;
    while (t--) {
        cin >> n >> m;
        vis.assign(n+1, false);
        adj.assign(n+1, vi());
        f(i,0,m,1) {
            cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
        int ans = 0;
        f(i,1,n+1,1) if (!vis[i]) ans = max(ans, bfs(i));
        cout << ans << nl;
    }
    return 0;
}
