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
	int n;
	vi p, rank;
public:
	UnionFind(int m) {
		n = m;
		p.assign(n, 0);
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
		return;
	}
};

int main() {
	int m, n;
	while (cin >> m >> n && m) {
		UnionFind uf(m);
		V<P<ll, pll>> edge(n);
		ll sm = 0, mst = 0;
		f(i,0,n,1) {
			ll x, y, z;
			cin >> x >> y >> z;
			sm += z;
			edge[i] = {z, {x, y}};
		}
		sort(all(edge));
		for (auto &[z, r] : edge) {
			auto &[x, y] = r;
			if (uf.isSameSet(x, y)) continue;
			uf.unionSet(x, y);
			mst += z;
		}
		cout << sm - mst << nl;
	}
	return 0;
}
