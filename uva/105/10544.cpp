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
#define INF (int)1e9

int main() {
    int t, n, m, qr;
    string rnk;
    char ch;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vvi AL(n);
        V<V<bool>> road(n, V<bool> (n, false));
        vi indeg(n), outdeg(n), topo, path(n);
        queue<int> q;
        f(i,0,m,1) {
            cin >> ch;
            int u = ch - 'A';
            cin >> ch;
            int v = ch - 'A';
            if (road[u][v]) continue;
            road[u][v] = true;
            AL[u].pb(v);
            ++indeg[v];
            ++outdeg[u];
        }
        f(i,0,n,1) {
            sort(all(AL[i]));
            if (!indeg[i])
                q.push(i);
            if (!outdeg[i])
                path[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.pb(u);
            for (int v : AL[u]) if (!(--indeg[v])) q.push(v);
        }
        reverse(all(topo));
        for (int u : topo) for (int v : AL[u]) path[u] += path[v];
        cin >> qr;
        f(i,0,qr,1) {
            cin >> rnk;
            int ans = 1, sz = rnk.size();
            f(i,1,sz,1) {
                int v0 = rnk[i] - 'A', u = rnk[i-1] - 'A';
                for (int v : AL[u]) {
                    if (v == v0) break;
                    ans += path[v];
                }
            }
            cout << rnk << ": " << ans << nl;
        }
    }
	return 0;
}
