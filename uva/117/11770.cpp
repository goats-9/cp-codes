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
vi dfs_num, topo;
int ctr;

void dfs(int u) {
    dfs_num[u] = ctr++;
    for (int v : adj[u])
        if (dfs_num[v] == -1) 
            dfs(v);
    topo.pb(u);
}

void dfs2(int u) {
    dfs_num[u] = ctr++;
    for (int v : adj[u])
        if (dfs_num[v] == -1)
            dfs2(v);
}

int main() {
    int n, m, x, y, t;
    cin >> t;
    f(k,1,t+1,1) {
        cin >> n >> m;
        ctr = 0;
        dfs_num.assign(n, -1);
        adj.assign(n, vi());
        topo.clear();
        vi indeg(n);
        f(i,0,m,1) {
            cin >> x >> y;
            adj[x-1].pb(y-1);
            ++indeg[y-1];
        }
        f(i,0,n,1) if (dfs_num[i] == -1 && indeg[i] == 0) dfs(i);
        f(i,0,n,1) if (dfs_num[i] == -1) dfs(i);
        reverse(all(topo));
        ctr = 0;
        dfs_num.assign(n, -1);
        int ans = 0;
        for (int u : topo) {
            if (dfs_num[u] == -1) {
                dfs2(u);
                ++ans;
            }
        }
        cout << "Case " << k << ": " << ans << nl;
    }
    return 0;
}
