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

class UnionFind {
private:
	vi p, rank;
public:
	UnionFind (int n) {
		p.assign(n,0);
		f(i,0,n,1) p[i] = i;
		rank.assign(n,0);
	}

	int findSet(int i) {return (p[i] == i) ? p[i] : (p[i] = findSet(p[i]));}

	bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}

	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x == y) return;
		if (rank[x] < rank[y]) swap(x, y);
		p[y] = x;
		if (rank[x] == rank[y]) ++rank[x];
	}
};

int main() {
	int n;
	int tc = 0;
	while (cin >> n && n) {
		V<pdd> coords(n);
		for (auto &[u, v] : coords) cin >> u >> v;
		V<P<double, pii>> edge;
		f(i,0,n,1) {
			f(j,i+1,n,1) {
				double w = sqrtl(powl(coords[i].first-coords[j].first,2) + powl(coords[i].second-coords[j].second,2));
				edge.pb({w, {i, j}});
			}
		}
		sort(all(edge));
		double ans = 0;
		UnionFind uf(n);
		int i = 0;
		while (!uf.isSameSet(0,1)) {
			ans = edge[i].first;
			auto &[u, v] = edge[i].second;
			uf.unionSet(u, v);
			i++;
		}
		cout << "Scenario #" << ++tc << nl << "Frog Distance = " << fixed << setprecision(3) << ans << nl << nl;
	}
	return 0;
}
