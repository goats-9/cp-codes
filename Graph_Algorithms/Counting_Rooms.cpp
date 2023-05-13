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
 
V<string> field;
vvi vis;
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
int n, m;
 
void dfs(int i, int j) { 
	vis[i][j] = 1;
	f(k, 0, 4, 1) { 
		int x = i + dx[k], y = j + dy[k];
		if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && field[x][y] == '.') dfs(x, y);
	}
}
 
int main() {
	int ctr = 0;
	cin >> n >> m;
	field.assign(n, "");
	vis.assign(n, vi(m, 0));
	f(i, 0, n, 1) cin >> field[i];
	f(i, 0, n, 1) f(j, 0, m, 1) if (!vis[i][j] && field[i][j] == '.') { dfs(i, j); ++ctr; }
	cout << ctr << nl;
}