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
	vi p, rank, sz;
public:
	UnionFind(int m) {
		n = m;
		p.assign(n,0);
		f(i,0,n,1) p[i] = i;
		rank.assign(n,0);
		sz.assign(n,1);
	}

	int findSet(int i) {return (p[i] == i) ? p[i] : (p[i] = findSet(p[i]));}

	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x == y) return;
		if (rank[x] < rank[y]) swap(x, y);
		p[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
		sz[x] += sz[y];
		return;
	}

	int getSize(int i) {
		int u = findSet(i);
		return sz[u];
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) { 
		int fr; cin >> fr;
		M<string, int> idx;
		int k = 0;
		V<pii> qr(fr);
		f(i,0,fr,1) {
			string p, q;
			cin >> p >> q;
			if (idx.find(p) == idx.end()) idx[p] = k++;
			if (idx.find(q) == idx.end()) idx[q] = k++;
			qr[i] = {idx[p], idx[q]};
		}
		UnionFind uf(k);
		f(i,0,fr,1) {
			auto &[u, v] = qr[i];
			uf.unionSet(u, v);
			cout << uf.getSize(u) << nl;
		}
	}
	return 0;
}
