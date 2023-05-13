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
#define N 627
 
V<string> field;
vvi vis, p;
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
string ps = "ULRD";
int n, m;
 
pii getStart() { f(i, 0, n, 1) f(j, 0, m, 1) if (field[i][j] == 'A') return pii(i, j); }
pii getEnd() { f(i, 0, n, 1) f(j, 0, m, 1) if (field[i][j] == 'B') return pii(i, j); }
 
void bfs(int i, int j) { 
	queue<pii> q;
	q.push(pii(i, j));
	vis[i][j] = 1;
	while (!q.empty()) { 
		int x = q.front().first, y = q.front().second;
		q.pop();
		f(k, 0, 4, 1) { 
			int u = x + dx[k], v = y + dy[k];
			if (u >= 0 && u < n && v >= 0 && v < m && !vis[u][v] && field[u][v] != '#') { 
				p[u][v] = k;
				q.push(pii(u, v));
				vis[u][v] = 1;
				if (field[u][v] == 'B') return;
			}  
		}
	}
}
 
int main() {
	cin >> n >> m;
	field.assign(n, "");
	vis.assign(n, vi(m));
	p.assign(n, vi(m));
	f(i, 0, n, 1) cin >> field[i];
	pii ret = getStart(), end = getEnd();
	bfs(ret.first, ret.second);
	if (vis[end.first][end.second]) { 
		cout << "YES\n";
		vi moves;
		int u = end.first, v = end.second;
		while (!(u == ret.first && v == ret.second)) { 
			int m = p[u][v];
			moves.pb(m);
			u -= dx[m], v -= dy[m];
		}
		cout << moves.size() << nl;
		reverse(all(moves));
		for (auto x: moves) cout << ps[x];
		cout << nl;
	} else cout << "NO\n";
	return 0;
}