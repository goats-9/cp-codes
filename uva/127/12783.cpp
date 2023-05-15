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

vvi adj;
vi dfs_num, dfs_low, dfs_parent;
int ctr;
V<pii> bridge;

void dfs(int u) {
    dfs_num[u] = ctr++;
    dfs_low[u] = dfs_num[u];
    for (int v : adj[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            dfs(v);
            if (dfs_low[v] > dfs_num[u])
                bridge.pb(pii(min(u, v), max(u, v)));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) 
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    int n, m, x, y;
    while (cin >> n >> m && n) {
        bridge.clear();
        ctr = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, n+1);
        dfs_parent.assign(n, -1);
        adj.assign(n, vi());
        f(i,0,m,1) {
            cin >> x >> y;
            adj[x].pb(y), adj[y].pb(x);
        }
        f(i,0,n,1) if (dfs_num[i] == -1) dfs(i);
        sort(all(bridge));
        cout << bridge.size();
        for (auto e : bridge) cout << ' ' << e.first << ' ' << e.second;
        cout << nl;
    }
    return 0;
}
