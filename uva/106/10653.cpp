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
	int r, c;
	vi dx = {0,0,1,-1};
	vi dy = {1,-1,0,0};
	while (cin >> r >> c && r) {
		vvi dp(r, vi(c)), vis(r, vi(c));
		int m;
		cin >> m;
		f(i,0,m,1) {
			int rw, sz;
			cin >> rw >> sz;
			f(j,0,sz,1) {
				int x;
				cin >> x;
				dp[rw][x] = -1;
			}
		}
		int sx, sy;
		cin >> sx >> sy;
		queue<pii> q;
		q.push({sx, sy});
		while (!q.empty()) {
			auto &[u, v] = q.front();
			q.pop();
			f(k,0,4,1) {
				int u1 = u + dx[k], v1 = v + dy[k];
				if (u1 < 0 || u1 >= r || v1 < 0 || v1 >= c || vis[u1][v1] || dp[u1][v1] == -1) continue;
				dp[u1][v1] = dp[u][v] + 1;
				vis[u1][v1] = 1;
				q.push({u1, v1});
			}
		}
		cin >> sx >> sy;
		cout << dp[sx][sy] << nl;
	}
	return 0;
}
