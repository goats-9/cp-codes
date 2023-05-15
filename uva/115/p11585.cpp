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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7

int vis[105][105], num[105][105], r, c, d, fl;
char board[105][105];
vi dx = {-1, 0, 0, 1, -1, -1, 1, 1};
vi dy = {0, 1, -1, 0, -1, 1, -1, 1};
vector<pii> num_list;

pii getShaded() { 
	f(i, 0, r, 1) f(j, 0, c, 1) if (board[i][j] == '#') return make_pair(i, j);
	return make_pair(-1, -1);
}

void shaded_bfs() {
	if (!fl) return;
	pii ret = getShaded();
	if (ret == make_pair(-1, -1)) return;
	queue<pii> q;
	q.push(ret);
	vis[ret.first][ret.second] = 1;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		f(k, 0, 4, 1) { 
			int i_new = i + dx[k], j_new = j + dy[k];
			if (i_new >= 0 && i_new < r &&
				j_new >= 0 && j_new < c &&
				board[i_new][j_new] == '#' &&
				!vis[i_new][j_new]) { 
				q.push(make_pair(i_new, j_new));
				vis[i_new][j_new] = 1;
			}
		} 
	}
	f(i, 0, r, 1) f(j, 0, c, 1) if (board[i][j] == '#' && !vis[i][j]) {fl = 0; return;}
}

void unshaded_number_bfs(int x, int y) { 
	if (!fl) return;
	if (board[x][y] == '#') {fl = 0; return;}
	queue<pii> q;
	q.push(make_pair(x, y));
	vis[x][y] = 1;
	int ctr = 1;
	while (!q.empty()) {
		int i_new, j_new, i = q.front().first, j = q.front().second;
		q.pop();
		f(k, 0, 4, 1) { 
			i_new = i + dx[k], j_new = j + dy[k];
			if (i_new >= 0 && i_new < r && j_new >= 0 && j_new < c &&
				board[i_new][j_new] == '.' && !vis[i_new][j_new]) { 
				if (num[i_new][j_new]) {fl = 0; return;}
				q.push(make_pair(i_new, j_new));
				vis[i_new][j_new] = 1; ++ctr;
			}
		} 
	}
	if (ctr != num[x][y]) fl = 0;
}

void edge_bfs(int x, int y) { 
	if (!fl) return;
	queue<pii> q;
	q.push(make_pair(x, y));
	int chk[r][c];
	reset(chk, 0);
	chk[x][y] = 1;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		if (i == 0 || i == r - 1 || j == 0 || j == c - 1) return;
		f(k, 0, 8, 1) { 
			int i_new = i + dx[k], j_new = j + dy[k];
			if (i_new >= 0 && i_new < r &&
				j_new >= 0 && j_new < c &&
				board[i_new][j_new] == '.' &&
				!chk[i_new][j_new]) { 
				q.push(make_pair(i_new, j_new));
				chk[i_new][j_new] = 1;
			}
		} 
	}
	fl = 0;
}

void unshd_chk() { 
	f(i, 0, r, 1) f(j, 0, c, 1) if (board[i][j] == '.' && !vis[i][j]) {fl = 0; return;} 
}

void num_edge_bfs() { 
	f(i, 0, d, 1) unshaded_number_bfs(num_list[i].first, num_list[i].second);
	unshd_chk();
	f(i, 1, r - 1, 1) f(j, 1, c - 1, 1) if (board[i][j] == '.') edge_bfs(i, j);
}

void subsqr() { 
	if (!fl) return;
	f(i, 0, r - 1, 1) { 
		f(j, 0, c - 1, 1) { 
			if (board[i][j] == '#' && board[i + 1][j] == '#' && board[i + 1][j + 1] == '#' && board[i][j + 1] == '#') {fl = 0; return;}
		}
	}
	return;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		scanf("%d %d %d", &r, &c, &d);
		reset(num, 0), reset(vis, 0), reset(board, 0);
		num_list.clear();
		int x, y, z;
		f(i, 0, d, 1) { 
			scanf("%d %d %d", &x, &y, &z);
			num[x][y] = z;
			num_list.pb(make_pair(x, y));
		}
		f(i, 0, r, 1) f(j, 0, c, 1) cin >> board[i][j];
		fl = 1;
		shaded_bfs();
		num_edge_bfs();
		subsqr();
		if (fl) cout << "solved\n";
		else cout << "not solved\n";
	}
	return 0;
}
