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
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vll s(n);
    f(i,0,n,1) cin >> s[i];
    V<V<pll>> adj(n, V<pll>());
    vi indeg(n);
    f(i,0,c,1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb({v, w});
        ++indeg[v];
    }
    queue<int> q;
    f(i,0,n,1) if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &[v, w] : adj[u]) {
            s[v] = max(s[v], s[u] + w);
            if (!(--indeg[v])) q.push(v);
        }
    }
    f(i,0,n,1) cout << s[i] << nl;
}
