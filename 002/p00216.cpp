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
#define LSOne(s) (s & (-s))

double memo[10][1024];
int order[10][1024], n;
V<pii> c;

double cost(int u, int v) { return sqrt(1.0*(pow((c[u].first - c[v].first),2) + pow((c[u].second - c[v].second), 2))); }

double dp(int u, int mask) { 
	double &ans = memo[u][mask];
	if (mask == 0) return ans = 0;
	if (ans != -1.0) return ans;
	ans = 1e9;
	int m = mask;
	while (m) { 
		int mk = LSOne(m), v = log2(mk);
		m -= mk;
		if (16 + cost(u, v) + dp(v, mask ^ mk) < ans) {
			order[u][mask] = v;
			ans = cost(u, v) + 16 + memo[v][mask ^ mk];
		}
	}
	return ans;
}

int main() {
	int tc = 0;
    while (cin >> n && n) { 
		c.assign(n, mp(0, 0));
		reset(order, -1);
		f(i, 0, 10, 1) f(j, 0, 1024, 1) memo[i][j] = -1.0;
		f(i, 0, n, 1) cin >> c[i].first >> c[i].second;
		cout << "**********************************************************\nNetwork #" << ++tc << nl;
		double ans = 1e9;
		int start = (1 << n) - 1, idx = 0;
		f(i, 0, n, 1) if (ans > dp(i, start^(1 << i))) ans = memo[i][start^(1 << i)], idx = i;
		int sm = ((1 << n) - 1) ^ (1 << idx);
		while (order[idx][sm] != -1) { 
			int x = idx, y = order[idx][sm];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", c[x].first, c[x].second, c[y].first, c[y].second, cost(x, y) + 16);	
			idx = y, sm ^= (1 << y);
		}
		printf("Number of feet of cable required is %.2lf.\n", ans);
	}
	return 0;
}
