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

int n, m, g;
vector<string> field;
int vis[64][64];

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void bfs(int i, int j) { 
	queue<pii> q; q.push(pii(i, j));
	vis[i][j] = 1;
	while (!q.empty()) { 
		pii c = q.front(); q.pop();
		int fl = 0;
		f(i, 0, 4, 1) { 
			int cx = c.first + dx[i], cy = c.second + dy[i];
			if (0 <= cx && cx < n && 0 <= cy && cy < m && field[cx][cy] == 'T') { 
				fl = 1;
				break;
			}
		}
		if (fl) continue;
		f(i, 0, 4, 1) { 
			int cx = c.first + dx[i], cy = c.second + dy[i];
			if (0 <= cx && cx < n && 0 <= cy && cy < m && !vis[cx][cy] && field[cx][cy] != 'T' && field[cx][cy] != '#') { 
				vis[cx][cy] = 1; q.push(pii(cx, cy));
				if (field[cx][cy] == 'G') ++g;
			}
		}
	}
}

pii start() { 
	f(i, 0, n, 1) f(j, 0, m, 1) if (field[i][j] == 'P') return pii(i, j);
	return pii(0, 0);
}

int main() {
    while (cin >> m >> n) { 
		field.assign(n, "");
		f(i, 0, n, 1) cin >> field[i];
		pii st = start();
		reset(vis, 0);
		g = 0;
		bfs(st.first, st.second);
		cout << g << nl;
	}
	return 0;
}
