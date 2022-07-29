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
int vis[512];
vector<vi> adj;
vi x = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
vi y = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int max_ppa;

int bfs(int idx) { 
	queue<int> q;
	q.push(idx);
	int ctr = 1;
	vis[idx] = 2;
	while (!q.empty()) { 
		int i = q.front();
		q.pop();
		f(j, 0, adj[i].size(), 1) if (vis[adj[i][j]] == 1) {
			vis[adj[i][j]] = 2;
			q.push(adj[i][j]);
			++ctr;
		}
	}
	return ctr;
}

int main() {
	cin.tie(NULL);
    while (1) { 
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		reset(vis, 0);
		adj.assign(n + 1, {});
		vector<pair<int, pii>> road(m);
		f(i, 0, m, 1) { 
			cin >> road[i].second.first >> road[i].second.second >> road[i].first;
		}
		sort(road.rbegin(), road.rend());
		max_ppa = road[0].first;
		int i = 0;
		while (road[i].first == max_ppa && i < m) { 
			vis[road[i].second.second] = 1, vis[road[i].second.first] = 1;
			adj[road[i].second.first].pb(road[i].second.second);
			adj[road[i].second.second].pb(road[i].second.first);
			++i;
		}
		int ans = 0;
		f(i, 1, n + 1, 1) if (vis[i] == 1) ans = max(ans, bfs(i));
		cout << ans << "\n";
	}
	return 0;
}
