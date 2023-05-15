#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = (int)a; i < (int)b; i = i + (int)j)
#define pb push_back

vector<vi> adj;
int vis[105];
vi ts;

void topsort(int u) { 
	vis[u] = 1;
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (!vis[v]) topsort(v);
	}
	ts.pb(u);
}

int main() {
    int n, m, a, b;
    while (cin >> n >> m) {
		if (!n) break;
		adj.assign(n, {});
		ts.clear();
		memset(vis, 0, sizeof(vis));
		f(i, 0, m, 1) { 
			cin >> a >> b;
			adj[a - 1].pb(b - 1);
		}
		f(i, 0, n, 1) { 
			if (!vis[i]) topsort(i);
		}
		f(i, 0, n, 1) { 
			cout << 1 + ts[n - 1 - i];
			if (i == n - 1) cout << "\n";
			else cout << " ";
		}
    }
    return 0;
}
