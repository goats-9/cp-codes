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
#define INF 1e9

vi fav, pr;
int memo[128][4096][32], n, x, t, k, maxpr, fvi;

int dp(int id, int val, int d) { 
	if (d > 2*(n + 1) || val + ceil(0.1*val) > maxpr) return -INF;
	if (id == k || d == 2*(n + 1)) return 0;
	int &ans = memo[id][val][d];
	if (ans != -1) return ans;
	return ans = max(dp(id + 1, val, d), max(fav[id] + dp(id + 1, val + pr[id], d +	1), 2*fav[id] + dp(id + 1, val + 2*pr[id], d + 2)));
}

int main() {
    while (cin >> n >> x >> t >> k && n) { 
		reset(memo, -1);
		pr.assign(k, 0);
		fav.assign(k, 0);
		maxpr = (n + 1)*x;
		f(i, 0, k, 1) { 
			cin >> pr[i];
			f(j, 0, n + 1, 1) {
				cin >> fvi;
				fav[i] += fvi;
			}
		}
		printf("%.2lf\n", max(dp(0, (n + 1)*t, 0)/(n + 1.0), 0.0));
	}
	return 0;
}
