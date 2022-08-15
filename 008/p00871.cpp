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

vi dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vi dy = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<string> field;
int vis[25][25], n, mx;

void bfs(int i, int j) { 
	queue<pii> q;
	q.push(pii(i, j));
	vis[i][j] = 1;
	int ctr = 0;
	while (!q.empty()) { 
		pii c = q.front(); q.pop();
		++ctr;
		f(i, 0, 8, 1) { 
			int cx = c.first + dx[i], cy = c.second + dy[i];
			if (0 <= cx && cx < n && 0 <= cy && cy < n && !vis[cx][cy] && field[cx][cy] == '1') {vis[cx][cy] = 1; q.push(pii(cx, cy));}
		}
	}
	mx = max(mx, ctr);
}

int main() {
	int t;
	string s;
    scanf("%d", &t);
    while (t--) { 
		cin >> s;
		n = s.size();
		field.assign(n, "");
		field[0] = s;
		f(i, 1, n, 1) cin >> field[i];
		mx = 0;
		reset(vis, 0);
		f(i, 0, n, 1) f(j, 0, n, 1) if (field[i][j] == '1' && !vis[i][j]) bfs(i, j);
		cout << mx << nl;
		if (t) cout << nl;
	}
	return 0;
}
