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

int n, ans;
vector<string> field;
int vis[128][128];

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void bfs(int i, int j) { 
	queue<pii> q; q.push(pii(i, j));
	vis[i][j] = 1;
	int fl = 0;
	while (!q.empty()) { 
		pii c = q.front(); q.pop();
		if (field[c.first][c.second] == 'x') fl = 1;
		f(k, 0, 4, 1) { 
			int cx = c.first + dx[k], cy = c.second + dy[k];
			if (0 <= cx && cx < n && 0 <= cy && cy < n && !vis[cx][cy] && (field[cx][cy] == '@' || field[cx][cy] == 'x')) { 
				vis[cx][cy] = 1;
				q.push(pii(cx, cy));
				if (field[cx][cy] == 'x') fl = 1;
			}
		}
	}
	ans += fl;
}

int main() {
	int t;
    scanf("%d", &t);
    f(k, 1, t + 1, 1) { 
		cin >> n;
		field.assign(n, "");
		f(i, 0, n, 1) cin >> field[i];
		reset(vis, 0);
		ans = 0;
		f(i, 0, n, 1) f(j, 0, n, 1) if (!vis[i][j] && (field[i][j] == '@' || field[i][j] == 'x')) bfs(i, j);
		cout << "Case " << k << ": " << ans << nl;
	}
	return 0;
}
