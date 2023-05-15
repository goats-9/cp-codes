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

int main() {
	int tc, n, m, s, t, u, v, w;
    scanf("%d", &tc);
    f(k, 1, tc + 1, 1) {
		scanf("%d %d %d %d", &n, &m, &s, &t);
		V<V<pii>> am(n, V<pii>());
		f(i, 0, m, 1) { 
			scanf("%d %d %d", &u, &v, &w);
			am[u].pb(pii(v, w));
			am[v].pb(pii(u, w));
		}
		vi dis(n, INF);
		dis[s] = 0;
		priority_queue<pii> pq; pq.push(pii(0, s));
		while (!pq.empty()) { 
			int v1 = pq.top().second, cw = -pq.top().first;
			pq.pop();
			if (v1 == t) break;
			if (dis[v1] < cw) continue; 
			f(i, 0, am[v1].size(), 1) { 
				int v2 = am[v1][i].first, dw = am[v1][i].second;
				if (dis[v2] > dw + cw) { 
					dis[v2] = dw + cw;
					pq.push(pii(-dis[v2], v2));
				}
			}
		}
		printf("Case #%d: ", k);
		if (dis[t] != INF) printf("%d\n", dis[t]);
		else printf("unreachable\n");
	}
	return 0;
}
