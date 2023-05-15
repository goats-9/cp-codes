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

int m, n, csz, vis[32][32], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
V<string> field;
pii king;
char LAND;

void bfs(int i, int j) { 
	queue<pii> q;
	q.push(pii(i, j));
	vis[i][j] = 1;
	int fl = 0, ctr = 1;
	if (pii(i, j) == king) fl = 1;
	while (!q.empty()) { 
		pii c = q.front(); q.pop();
		f(k, 0, 4, 1) { 
			int cx = c.first + dx[k], cy = (c.second + n + dy[k])%n;
			if (0 <= cx && cx < m && !vis[cx][cy] && field[cx][cy] == LAND) { 
				if (pii(cx, cy) == king) fl = 1;
				q.push(pii(cx, cy));
				vis[cx][cy] = 1;
				++ctr;
			}
		}
	}
	if (fl) return;
	else csz = max(csz, ctr);
}

int main() {
    while (cin >> m >> n) { 
		field.assign(m, "");
		csz = 0;
		reset(vis, 0);
		f(i, 0, m, 1) cin >> field[i];
		cin >> king.first >> king.second;
		LAND = field[king.first][king.second];
		f(i, 0, m, 1) f(j, 0, n, 1) if (!vis[i][j] && field[i][j] == LAND) bfs(i, j);
		cout << csz << nl;
	}
	return 0;
}
