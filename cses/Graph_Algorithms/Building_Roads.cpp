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
 
int main() {
	int n, m, x, y;
	cin >> n >> m;
	vi vis(n + 1);
	vvi adj(n + 1, vi());
	f(i, 0, m, 1) { 
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vi rep;
	f(i, 1, n + 1, 1) if (!vis[i]) { 
		queue<int> q; q.push(i);
		vis[i] = 1;
		rep.pb(i);
		while (!q.empty()) { 
			int u = q.front(); q.pop();
			f(i, 0, adj[u].size(), 1) { 
				int v = adj[u][i];
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	cout << rep.size() - 1 << nl;
	f(i, 0, rep.size() - 1, 1) cout << rep[i] << " " << rep[i + 1] << nl;
	return 0;
}