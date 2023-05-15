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
#define INF int(1e9)

int main() {
	int r1, r2, r3, c1, c2, c3, tc = 0;
    while (cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3) { 
		vvi dis(9, vi(9, INF));
		dis[r1][c1] = 0;
		vi dx = {-1, -1, -1, 0, 0, 1, 1, 1}, dy = {-1, 0, 1, -1, 1, -1, 0, 1};
		queue<pii> q;
		q.push(mp(r1, c1));
		while (!q.empty()) { 
			pii u = q.front(); q.pop();
			if (u == mp(r2, c2)) break;
			f(i, 0, 8, 1) {
				int xn = u.first + dx[i], yn = u.second + dy[i];
				if (xn > 0 && xn < 9 && yn > 0 && yn < 9 && !(xn == r3 && yn == c3) && dis[xn][yn] == INF) { 
					dis[xn][yn] = dis[u.first][u.second] + 1;
					q.push(mp(xn, yn));
				}
			}
		}
		cout << "Case " << ++tc << ": " << dis[r2][c2] << nl;
	}
	return 0;
}
