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

int b, w, fb, fw;
vector<string> field(9);
int vis[9][9];

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void bfs(int i, int j) { 
	queue<pii> q; q.push(pii(i, j));
	int ctr = 1;
	fb = 0, fw = 0;
	vis[i][j] = 1;
	while (!q.empty()) { 
		pii c = q.front();
		q.pop();
		f(k, 0, 4, 1) { 
			int cx = c.first + dx[k], cy = c.second + dy[k];
			if (0 <= cx && cx < 9 && 0 <= cy && cy < 9 && !vis[cx][cy]) { 
				if (field[cx][cy] == '.') { 
					vis[cx][cy] = 1;
					q.push(pii(cx, cy));
					++ctr;
				} else if (field[cx][cy] == 'X') fb = 1;
				else fw = 1;
			}
		}
	}
	if (fb && !fw) b += ctr;
	else if (fw && !fb) w += ctr;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		f(i, 0, 9, 1) cin >> field[i];
		reset(vis, 0);
		b = 0, w = 0;
		int bs = 0, ws = 0;
		f(i, 0, 9, 1) f(j, 0, 9, 1) { 
			if (!vis[i][j] && field[i][j] == '.') bfs(i, j);
			if (field[i][j] == 'X') ++bs;
			else if (field[i][j] == 'O') ++ws;
		}
		cout << "Black " << b + bs << " White " << w + ws << nl;
	}
	return 0;
}
