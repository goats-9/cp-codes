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

int n, m;
V<string> field;
vi holes;
M<char, string> h2bc;

string h2b(string &s) { 
	string c = "";
	f(i, 0, s.size(), 1) c += h2bc[s[i]];
	return c;
}

int vis[200][200], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, VIS;
char CH;

void bfs(int i, int j) { 
	queue<pii> q; q.push(pii(i, j));
	vis[i][j] = VIS;
	while (!q.empty()) { 
		pii c = q.front(); q.pop();
		f(k, 0, 4, 1) { 
			int cx = c.first + dx[k], cy = c.second + dy[k];
			if (0 <= cx && cx < n && 0 <= cy && cy < 4*m && !vis[cx][cy] && field[cx][cy] == CH) { 
				q.push(pii(cx, cy));
				vis[cx][cy] = VIS;
			}
		}
	}
}

int bfs2(int i, int j) { 
	queue<pii> q; q.push(pii(i, j));
	vis[i][j] = VIS;
	int ans = -1;
	while (!q.empty()) { 
		pii c = q.front(); q.pop();
		f(k, 0, 4, 1) { 
			int cx = c.first + dx[k], cy = c.second + dy[k];
			if (0 <= cx && cx < n && 0 <= cy && cy < 4*m) {
				if (!vis[cx][cy] && field[cx][cy] == CH) { 
					q.push(pii(cx, cy));
					vis[cx][cy] = VIS;
				} else if (field[cx][cy] != CH) {
					ans = vis[cx][cy];
				}
			}
		}
	}
	return ans;
}

V<char> hg = {'W', 'A', 'K', 'J', 'S', 'D'};

int main() {
	string s;
	int tc = 0;
	h2bc['0'] = "0000"; h2bc['1'] = "0001"; h2bc['2'] = "0010"; h2bc['3'] = "0011"; h2bc['4'] = "0100"; h2bc['5'] = "0101"; h2bc['6'] = "0110"; h2bc['7'] = "0111"; h2bc['8'] = "1000"; h2bc['9'] = "1001"; h2bc['a'] = "1010"; h2bc['b'] = "1011"; h2bc['c'] = "1100"; h2bc['d'] = "1101"; h2bc['e'] = "1110"; h2bc['f'] = "1111";
    while (cin >> n >> m && n) { 
		reset(vis, 0);
		field.assign(n, "");
		f(i, 0, n, 1) { 
			cin >> s;
			field[i] = h2b(s);
		}
		VIS = 1; CH = '0';
		f(i, 0, n, 1) { 
			f(j, 0, 4*m, 1) { 
				if ((i == 0 || i == n - 1 || j == 0 || j == 4*m - 1) && !vis[i][j] && field[i][j] == CH) {
					bfs(i, j); 
				}
			}
		}
		CH = '1';
		f(i, 0, n, 1) { 
			f(j, 0, 4*m, 1) { 
				if (!vis[i][j] && field[i][j] == CH) { 
					++VIS;
					bfs(i, j);
				}
			}
		}
		holes.assign(VIS - 1, 0);
		CH = '0'; VIS = 1;
		f(i, 0, n, 1) { 
			f(j, 0, 4*m, 1) { 
				if (!vis[i][j] && field[i][j] == CH) { 
					holes[bfs2(i, j) - 2]++;
				}
			}
		}
		s = "";
		f(i, 0, holes.size(), 1) s += hg[holes[i]];
		sort(s.begin(), s.end());
		cout << "Case " << ++tc << ": " << s << nl;
	}
	return 0;
}
