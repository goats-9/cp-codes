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
V<string> field;
V<V<bool>> vis;
vvi p;
pii cur, start;
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
string dc = "ULRD";
 
bool esc() { 
	queue<pii> q1, q2;
	f(i, 0, n, 1) f(j, 0, m, 1) { 
		if (field[i][j] == 'A') { start = pii(i, j); q1.push(start); vis[i][j] = true; }
		if (field[i][j] == 'M') q2.push(pii(i, j));
	}
	while (!q1.empty()) { 
		int sz = q2.size();
		f(i, 0, sz, 1) { 
			int x = q2.front().first, y = q2.front().second; q2.pop();
			f(k, 0, 4, 1) { 
				int u = x + dx[k], v = y + dy[k];
				if (u >= 0 && u < n && v >= 0 && v < m && field[u][v] == '.') { 
					field[u][v] = 'M';
					q2.push(pii(u, v));
				}
			}
		}
		sz = q1.size();
		f(i, 0, sz, 1) { 
			int x = q1.front().first, y = q1.front().second; q1.pop();
			if (x == 0 || x == n - 1 || y == 0 || y == m - 1) { cur = pii(x, y); return true; }
			f(k, 0, 4, 1) { 
				int u = x + dx[k], v = y + dy[k];
				if (u >= 0 && u < n && v >= 0 && v < m && !vis[u][v] && field[u][v] == '.') { 
					vis[u][v] = 1;
					p[u][v] = k;
					q1.push(pii(u, v));
				}
			}
		}
	}
	return false;
}
 
int main() {
	cin >> n >> m;
	field.assign(n, "");
	f(i, 0, n, 1) cin >> field[i];
	vis.assign(n, V<bool>(m, false));
	p.assign(n, vi(m, -1));
	if (esc()) { 
		cout << "YES\n";
		string path = "";
		while (cur != start) { 
			int k = p[cur.first][cur.second];
			cur.first -= dx[k], cur.second -= dy[k];
			path += dc[k];
		}
		reverse(all(path));
		cout << path.size() << nl << path << nl;
	} else cout << "NO\n";
	return 0;
}