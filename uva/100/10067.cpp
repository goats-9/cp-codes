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
	while (t--) { 
		int p = 0, q = 0;
		f(i,0,4,1) {
			int x; cin >> x;
			p = 10*p + x;
		}
		f(i,0,4,1) {
			int x; cin >> x;
			q = 10*q + x;
		}
		vi dis(10000, MOD1);
		int n;
		cin >> n;
		f(i,0,n,1) {
			int b = 0;
			f(j,0,4,1) {
				int x;
				cin >> x;
				b = 10*b + x;
			}
			if (b == p) continue;
			dis[b] = -1;
		}
		dis[p] = 0;
		queue<int> bfs; bfs.push(p);
		while (!bfs.empty()) {
			int u = bfs.front(); bfs.pop();
			int v;
			v = u - 1;
			if (v/10 != u/10 || v < 0) v += 10;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u + 1;
			if (v/10 != u/10) v -= 10;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u - 10;
			if (v/100 != u/100 || v < 0) v += 100;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u + 10;
			if (v/100 != u/100) v -= 100;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u - 100;
			if (v/1000 != u/1000 || v < 0) v += 1000;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u + 100;
			if (v/1000 != u/1000) v -= 1000;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u - 1000;
			if (v/10000 != u/10000 || v < 0) v += 10000;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
			v = u + 1000;
			if (v/10000 != u/10000) v -= 10000;
			if (dis[v] == MOD1) {
				dis[v] = dis[u] + 1;
				bfs.push(v);
			}
		}
		if (dis[q] == MOD1) dis[q] = -1;
		cout << dis[q] << nl;
	}
	return 0;
}
