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
#define MOD 1000000007
 
int n, m;
vi vis;
vvi adj;
 
bool bfs(int u) { 
	int c = 1;
	queue<pii> q; q.push(pii(u, c));
	vis[u] = c;
	while (!q.empty()) { 
		int u = q.front().first;
		c = 3 - q.front().second;
		q.pop();
		f(i, 0, adj[u].size(), 1) { 
			int v = adj[u][i];
			if (vis[v] != -1) { 
				if (vis[v] != c) return false;
			} else {
				vis[v] = c;
				q.push(pii(v, c));
			}
		}
	}
	return true;
}
 
int main() {
	cin >> n >> m;
	int x, y;
	vis.assign(n + 1, -1);
	adj.assign(n + 1, vi());
	f(i, 0, m, 1) { 
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bool fl = true;
	f(i, 1, n + 1, 1) { 
		if (vis[i] == -1 && !bfs(i)) { 
			fl = false;
			break;
		} 
	}
	if (fl) f(i, 1, n + 1, 1) cout << vis[i] << " ";
	else cout << "IMPOSSIBLE";
	cout << nl;
	return 0;
}