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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

vvi adj;
vi vis;
int memo[10010][3];

void dp(int u) { 
	vis[u] = 1;
	memo[u][0] = 1;
	memo[u][1] = 0;
	memo[u][2] = 1 << 20;
	vi arr;
	f(i, 0, adj[u].size(), 1) { 
		int v = adj[u][i];
		if (!vis[v]) { 
			arr.pb(v);
			dp(v);
			memo[u][0] += min(memo[v][0], memo[v][1]);
			memo[u][1] += memo[v][2];
		}
	}
	f(i, 0, arr.size(), 1) { 
		int v = arr[i];
		memo[u][2] = min(memo[u][2], memo[u][1] - memo[v][2] + memo[v][0]);
	}
}

int main() {
	int n, x, y;
	while (cin >> n) { 
		adj.assign(n + 1, vi());
		vis.assign(n + 1, 0);
		reset(memo, 0);
		f(i, 0, n - 1, 1) { 
			cin >> x >> y;
			adj[x].pb(y), adj[y].pb(x);
		}
		dp(1);
		cout << min(memo[1][0], memo[1][2]) << nl;
		cin >> n;
		if (n == -1) break;
	}
	return 0;
}
