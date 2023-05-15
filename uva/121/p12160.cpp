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
#define INF (int)1e9
#define N 10000


int main() {
	int tc = 0, l, u, r;
    while (cin >> l >> u >> r && r) { 
		vi dis(N, INF);
		vi num(10);
		dis[l] = 0;
		f(i, 0, r, 1) cin >> num[i];
		queue<int> q; q.push(l);
		while (!q.empty()) { 
			int v = q.front(); q.pop();
			if (v == u) break;
			f(i, 0, r, 1) { 
				int w = (v + num[i])%N;
				if (dis[w] == INF) { 
					dis[w] = dis[v] + 1;
					q.push(w);
				}
			}
		}
		cout << "Case " << ++tc <<": ";
		if (dis[u] == INF) cout << "Permanently Locked\n";
		else cout << dis[u] << nl;
	}
	return 0;
}
