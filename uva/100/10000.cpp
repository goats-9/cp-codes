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
	int n;
	int tc = 0;
	while (cin >> n && n) {
		int s;
		cin >> s;
		vi dis(n+1, -1), indeg(n+1);
		dis[s] = 0;
		vvi adj(n+1, vi());
		int u, v;
		while (cin >> u >> v && u) adj[u].pb(v), ++indeg[v];
		queue<int> q; 
		f(i,1,n+1,1) if (!indeg[i]) q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == s) continue;
			for (auto v : adj[u]) {
				--indeg[v];
				if (!indeg[v]) q.push(v);
			}
		}
		q.push(s);
		dis[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v : adj[u]) {
				--indeg[v];
				if (!indeg[v]) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		cout << "Case " << ++tc << ": The longest path from " << s 
			 << " has length " << *max_element(all(dis)) << ", finishing at " 
			 << max_element(all(dis)) - dis.begin() << ".\n\n";
	}
	return 0;
}
