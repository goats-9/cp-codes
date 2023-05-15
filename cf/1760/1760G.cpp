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

V<V<pii>> adj;
set<pii> za, zb;
V<bool> vis;
int n, a, b;

void dfs(int u, int val, bool fl) {
    if (fl) {
        if (u != a) za.insert(pii(val, u));
        if (u == b) return;
    } else {
        if (u != b) zb.insert(pii(val, u));
    }
    f(i, 0, adj[u].size(), 1) { 
        int v = adj[u][i].first, w = adj[u][i].second;
        if (!vis[v]) {
            vis[v] = true;
            dfs(v, val ^ w, fl);
            vis[v] = false;
        }
    }
}

bool check() { 
    for (pii t : zb) { 
        if (t.first == 0) return true;
        int k = t.first;
        auto s = za.lower_bound(pii(k, -1));
        while (s != za.end() && (*s).first == k) { 
            if ((*s).second != b) return true;
            ++s;
        }
    }
    return false;
}

int main() {
	int t, u, v, w;
    scanf("%d", &t);
    while (t--) {
        cin >> n >> a >> b;
        adj.assign(n + 1, V<pii>());
        f(i, 0, n - 1, 1) { 
            cin >> u >> v >> w;
            adj[u].pb(pii(v, w));
            adj[v].pb(pii(u, w));
        }
        za = set<pii>();
        zb = set<pii>();
        vis.assign(n + 1, false);
        vis[a] = true;
        dfs(a, 0, true);
        vis.assign(n + 1, false);
        vis[b] = true;
        dfs(b, 0, false);
        if (check()) cout << "YES\n";
        else cout << "NO\n";
        //for (pii t : za) cout << t.first << " " << t.second << nl;
        //cout << "---\n";
        //for (pii t : zb) cout << t.first << " " << t.second << nl;
        //cout << "---\n";
        //for (pii t : za) { 
        //    int k = t.first, l = t.second;
        //    if (k == 0 && l == b) {fl = true; break;}
        //    auto s = zb.lower_bound(pii(k, -1));
        //    bool int_fl = false;
        //    while (s != zb.end() && (*s).first == k) {
        //        if ((*s).second != a) {int_fl = true; break;}
        //        ++s;
        //    }
        //    if (int_fl) {fl = true; break;}
        //}
        //for (pii t : zb) { 
        //    int k = t.first, l = t.second;
        //    if (k == 0 && l != a) {fl = true; break;}
        //}
        //if (fl) cout << "YES\n";
        //else cout << "NO\n";
	}
	return 0;
}