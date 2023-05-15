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
#define MOD (int)1e9 + 7

vi vis;
vector<vi> adj;

void bfs(int u) { 
	queue<int> q;
	q.push(u);
	while (!q.empty()) { 
		int v = q.front();
		q.pop();
		vis[v] = 1;
		f(i, 0, adj[v].size(), 1) { 
			int v1 = adj[v][i];
			if (!vis[v1]) q.push(v1);
		}
	}
}

int main() {
	int t;
	string s;
    scanf("%d", &t);
    while (t--) {
		int tr = 0, ac = 0;
		vis.assign(26, -1);
		adj.assign(26, vi ());
		while (cin >> s && s[0] == '(') { 
			adj[s[1] - 'A'].pb(s[3] - 'A');
			adj[s[3] - 'A'].pb(s[1] - 'A');
		} 
		cin >> s;
		int sz = s.size();
		f(i, 0, sz, 2) vis[s[i] - 'A'] = 0;
		f(i, 0, 26, 1) { 
			if (!vis[i]) { 
				if ((int)adj[i].size() == 0) { ++ac; vis[i] = 1; }
				else {bfs(i); ++tr;}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tr, ac);
	}
	return 0;
}
