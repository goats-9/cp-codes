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

vvll adj;
vll desc, descsm, ans;
int n;

void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        desc[u] += 1 + desc[v];
        descsm[u] += desc[v] + 1 + descsm[v];
    }
}

void dfs2(int u, int p) {
    if (p == -1) ans[u] = descsm[u];
    else ans[u] = ans[p] + n - 2*(1 + desc[u]);
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u);    
    }
}

int main() {
    cin >> n;
    adj.assign(n+1, vll());
    f(i,0,n-1,1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    desc.assign(n+1,0);
    descsm.assign(n+1,0);
    ans.assign(n+1,0);
    dfs(1, -1); dfs2(1, -1);
    f(i,1,n+1,1) cout << ans[i] << ' ';
    cout << nl;
	return 0;
}
