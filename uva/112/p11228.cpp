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

int n, r, cc;
double rd, rl;
V<pii> coords;
V<pair<double, pii>> cost;
vi vis;
vvi adj;

double dis(int a, int b) { return sqrt(pow(coords[a].first - coords[b].first, 2) + pow(coords[a].second - coords[b].second, 2)); }

void bfs(int u) { 
	queue<int> q;
	q.push(u);
	while (!q.empty()) { 
		int p = q.front();
		q.pop();
		vis[p] = 1;
		f(i, 0, adj[p].size(), 1) if (!vis[adj[p][i]]) q.push(adj[p][i]); 
	}
}

class UnionFind { 
private:
	vi p;
	int n;
public:
	UnionFind(int sz) {
		n = sz;
		p.assign(n, 0);
		f(i, 0, n, 1) p[i] = i;
	}

	int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) { 
		if (!isSameSet(i, j)) { 
			int x = findSet(i), y = findSet(j);
			p[y] = x;
		}
	}
};

int main() {
	int t;
    scanf("%d", &t);
    f(k, 1, t + 1, 1) { 
		cin >> n >> r;
		coords.assign(n, mp(0, 0));
		vis.assign(n, 0);
		adj.assign(n, vi());
		cost.clear();
		f(i, 0, n, 1) cin >> coords[i].first >> coords[i].second;
		f(i, 0, n, 1) f(j, i + 1, n, 1) {
			cost.pb(mp(dis(i, j), mp(i, j)));
			if (dis(i, j) <= r) adj[i].pb(j), adj[j].pb(i);
		}
		sort(cost.begin(), cost.end());
		UnionFind uf(n);
		rd = rl = 0.0;
		f(i, 0, cost.size(), 1) { 
			int u = cost[i].second.first, v = cost[i].second.second;
			if (!uf.isSameSet(u, v)) {
				uf.unionSet(u, v);
				if (dis(u, v) <= r) rd += cost[i].first;
				else rl += cost[i].first;
			}
		}
		cc = 0;
		f(i, 0, n, 1) if (!vis[i]) { bfs(i); ++cc; }
		cout << "Case #" << k << ": " << cc << " " << round(rd) << " " << round(rl) << nl;
	}
	return 0;
}
