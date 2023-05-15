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

int n, m, M, c[256];
vector<vi> e;

void bfs(int u) { 
	queue<int> q;
	c[u] = 0;
	vi v;
	int c0 = 1, c1 = 0, fl = 0;
	q.push(u);
	v.pb(u);
	while (!q.empty()) { 
		int k = q.front(), clr = 1 - c[k];
		q.pop();
		f(i, 0, e[k].size(), 1) {
			if(c[e[k][i]] == -1) { 
				q.push(e[k][i]);
				c[e[k][i]] = clr;
				v.pb(e[k][i]);
				clr ? ++c1 : ++c0;
			} else if (c[e[k][i]] != clr) fl = 1;
		}
	}
	if (fl) {
		c0 = 0, c1 = 0;
		f(i, 0, v.size(), 1) c[v[i]] = 2;
	}
	m += min(c0, c1);
	M += max(c0, c1);
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) {
		reset(c, -2);
		m = 0, M = 0;
		cin >> n;
		e.assign(n, {});
		f(i, 0, n, 1) {
			c[i] = -1;
			int p, en; 
			cin >> p;
			f(j, 0, p, 1) { 
				cin >> en;
				if (en > n) continue;
				c[en - 1] = -1;
				e[i].pb(en - 1); 
				e[en - 1].pb(i); 
			}
		}
		f(i, 0, 256, 1) { 
			if (c[i] == -1) bfs(i);
		}
		cout << M << "\n";
	}
	return 0;
}
