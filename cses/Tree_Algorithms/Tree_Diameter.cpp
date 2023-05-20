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

int main() {
    int n; cin >> n;
    vvi adj(n+1, vi());
    f(i,0,n-1,1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi dist(n+1,INF), vis(n+1);
    dist[1] = 0; vis[1] = 0;
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                dist[v] = min(dist[v], dist[u] + 1);
            }
        }
    }
    int x = max_element(1+all(dist)) - dist.begin();
    dist.assign(n+1,INF), vis.assign(n+1,0);
    dist[x] = 0; vis[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                dist[v] = min(dist[v], dist[u] + 1);
            }
        }
    }
    cout << *max_element(1+all(dist)) << nl;
	return 0;
}
