#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

bool isBipartiteTool(vector<vi> &adj, int &x, vi &node) {
    queue<int> q;
    int t = adj.size();
    q.push(x);
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        f(i, 0, t, 1) {
            if (adj[y][i]) {
                if (node[i] == -1) {
                    node[i] = 1 - node[y];
                    q.push(i);
                }
                else if (node[i] == node[y]) return false;
            } 
        }
    }
    return true;
}

bool isBipartite(vector<vi> &adj) {
    vi node;
    int t = adj.size();
    node.assign(t, -1);
    f(i, 0, t, 1) if (node[i] == -1) if (!isBipartiteTool(adj, i, node)) return false;
    return true;
} 

int main() {
    int t, n, x, y;
    while (cin >> t) {
        if (!t) break;
        cin >> n;
        vector<vi> adj(t, vi (t));
        f(i, 0, n, 1) {
            cin >> x >> y;
            adj[x][y] = 1, adj[y][x] = 1;
        }
        isBipartite(adj) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}