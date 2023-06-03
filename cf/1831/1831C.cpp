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
	int t;
	cin >> t;
	while (t--) { 
        int n;
        cin >> n;
        V<V<pii>> adj(n+1, V<pii>());
        f(i,0,n-1,1) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(pii(i, v));
            adj[v].pb(pii(i, u));
        }
        queue<P<int, pii>> q;
        V<bool> vis(n+1, false);
        vis[1] = true;
        q.push(mp(1, pii(1,0)));
        int ans = 1;
        while (!q.empty()) {
            auto &[x, p] = q.front();
            ans = max(ans, x);
            q.pop();
            auto &[u, id] = p;
            for (auto &[nxtid, v] : adj[u]) {
                if (vis[v]) continue;
                if (nxtid < id) {
                    q.push(mp(x+1,pii(v, nxtid)));
                } else {
                    q.push(mp(x, pii(v, nxtid)));
                }
                vis[v] = true;
            }
        }
        cout << ans << nl;
	}
	return 0;
}
