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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	int t;
	cin >> t;
	V<pii> moves = {
		{1,0},
		{-1,0},
		{0,1},
		{0,-1},
	};
	f(k,1,t+1,1) { 
		int n, m;
		cin >> n >> m;
		V<string> a(n);
		vi lang(26);
		for (auto &x : a) cin >> x;
		vvi vis(n, vi(m));
		f(i,0,n,1) {
			f(j,0,m,1) {
				if (vis[i][j]) continue;
				char ch = a[i][j];
				++lang[ch-'a'];
				queue<pii> q;
				q.push({i,j});
				vis[i][j] = 1;
				while (!q.empty()) {
					auto &[u, v] = q.front(); q.pop();
					for (auto &[dx, dy] : moves) {
						int u1 = u + dx, v1 = v + dy;
						if (u1 >= 0 && u1 < n && v1 >= 0 && v1 < m && a[u1][v1] == ch && !vis[u1][v1]) {
							vis[u1][v1] = 1;
							q.push({u1,v1});
						}
					}
				}
			}
		}
		V<pii> ord;
		f(i,0,26,1) if (lang[i]) ord.pb({lang[i], -i});
		sort(rall(ord));
		cout << "World #" << k << nl;
		for (auto &[num, ch] : ord) cout << char('a'-ch) << ": " << num << nl;
	}
	return 0;
}
