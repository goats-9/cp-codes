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
	int numSets;
public:
	UnionFind(int n) {
		p.assign(n,0);
		f(i,0,n,1) p[i] = i;
		rank.assign(n,0);
		numSets = n;
	}

	int findSet(int i) {return (p[i] == i) ? p[i] : (p[i] = findSet(p[i]));}

	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x == y) return;
		if (rank[x] < rank[y]) swap(x, y);
		p[y] = x;
		if (rank[x] == rank[y]) ++rank[x];
		--numSets;
	}

	int getNumSets() {return numSets;}
};

int main() {
	int t;
	cin >> t;
	while (t--) { 
		int s, p;
		cin >> s >> p;
		V<pdd> coords(p);
		for (auto &[x, y] : coords) cin >> x >> y;
		V<P<double, pii>> el;
		f(i,0,p,1) {
			f(j,i+1,p,1) {
				double dist = sqrtl(powl(coords[i].first-coords[j].first,2)+powl(coords[i].second-coords[j].second,2));
				el.pb({dist, {i,j}});	
			}
		}
		sort(all(el));
		UnionFind uf(p);
		double ans = 0;
		for (auto &[w, p] : el) {
			auto &[u, v] = p;
			uf.unionSet(u, v);
			ans = w;
			if (uf.getNumSets() == s) break;
		}
		cout << fixed << setprecision(2) << ans << nl;
	}
	return 0;
}
