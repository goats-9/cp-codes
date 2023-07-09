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
#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vvi adj(n, vi());
    f(i,0,m,1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    int cl = INF;
    f(i,0,n,1) {
        vi dis(n, INF);
        dis[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (dis[v] == INF) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                } else if (dis[v] >= dis[u]) {
                    cl = min(cl, dis[v] + dis[u] + 1);
                }
            }
        }
    }
    if (cl == INF) cl = -1;
    cout << cl << nl;
	return 0;
}
