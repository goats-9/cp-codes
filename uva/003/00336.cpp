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

int main() {
    int nc, x, y;
    int num = 1;
    while (cin >> nc && nc) {
        M<int, vi> adj;
        M<int, bool> vis;
        f(i,0,nc,1) {
            cin >> x >> y;
            adj[x].pb(y), adj[y].pb(x);
            vis[x] = false, vis[y] = false;
        }
        while (cin >> x >> y && x) {
            queue<int> bfs; bfs.push(x);
            for (auto &b : vis) b.second = false;
            vis[x] = true;
            int ctr = vis.size() - 1;
            f(i,0,y,1) {
                int sz = bfs.size();
                f(j,0,sz,1) {
                    int u = bfs.front(); bfs.pop();
                    for (auto v : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            bfs.push(v);
                            --ctr;
                        }
                    }
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", num++, ctr, x, y);
        }
    }
	return 0;
}
