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
		vvi nodes;
		vi inp(3);
		f(i,0,n,1) {
			cin >> inp[0] >> inp[1] >> inp[2];
			sort(all(inp));
			do nodes.pb(inp);
			while (next_permutation(all(inp)));
		}
		int sz = nodes.size();
		vvi adj(sz, vi());
		vi indeg(sz);
		f(i,0,sz,1) {
			f(j,i+1,sz,1) {
				if (nodes[i][0] > nodes[j][0] && nodes[i][1] > nodes[j][1]) adj[j].pb(i), ++indeg[i];
				else if (nodes[j][0] > nodes[i][0] && nodes[j][1] > nodes[i][1]) adj[i].pb(j), ++indeg[j];
			}
		}
		vi ans(sz, 0);
		queue<int> q;
		f(i,0,sz,1) if (!indeg[i]) {
			ans[i] = nodes[i][2];
			q.push(i);
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : adj[u]) {
				--indeg[v];
				ans[v] = max(ans[v], ans[u] + nodes[v][2]);
				if (!indeg[v]) q.push(v);
			}
		}
		cout << "Case " << ++tc << ": maximum height = " << *max_element(all(ans)) << nl;
	}
	return 0;
}
