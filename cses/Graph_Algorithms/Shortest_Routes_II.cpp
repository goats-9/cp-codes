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
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1000000007
#define INF 1000000000000LL
 
int main() {
	int n, m, q, a, b; ll c;
	cin >> n >> m >> q;
	vvll ans(n + 1, vll(n + 1, INF));
	vvll cost(n + 1, vll(n + 1, INF));
	f(i, 0, m, 1) { 
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
		cost[b][a] = min(cost[b][a], c);
	}
	f(i, 1, n + 1, 1) cost[i][i] = 0;
	f(k, 1, n + 1, 1) { 
		f(i, 1, n + 1, 1) { 
			f(j, 1, n + 1, 1) { 
				if (cost[i][j] > cost[i][k] + cost[k][j]) { 
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
	f(i, 0, q, 1) { 
		cin >> a >> b;
		if (cost[a][b] == INF) cout << -1 << nl;
		else cout << cost[a][b] << nl;
	}
	return 0;
}