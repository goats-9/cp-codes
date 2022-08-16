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

class UnionFind { 
private: vi p, rank; int n;
public:
	UnionFind(int sz) { 
		n = sz;
		p.assign(n, 0);
		f(i, 0, n, 1) p[i] = i;
		rank.assign(n, 1);
	}

	int findSet(int i) {return (p[i] == i) ? p[i] : p[i] = findSet(p[i]); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	
	void unionSet(int i, int j) { 
		if (!isSameSet(i, j)) { 
			int x = findSet(i), y = findSet(j);
			if (rank[x] < rank[y]) p[x] = y;
			else { 
				p[y] = x;
				if (rank[x] == rank[y]) ++rank[y];
			}
		}
	}
};

int main() {
	int t, n;
    scanf("%d", &t);
    f(k, 0, t, 1) { 
		if (k) cout << nl;
		cin >> n;
		V<pdd> coords(n, mp(0.0, 0.0));
		V<pair<double, pii>> edge;
		f(i, 0, n, 1) cin >> coords[i].first >> coords[i].second;
		f(i, 0, n, 1) { 
			f(j, i + 1, n, 1) { 
				edge.pb(mp(sqrt(pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2)), pii(i, j)));
			}
		}
		sort(edge.begin(), edge.end());
		double ans = 0;
		UnionFind uf(n);
		f(i, 0, edge.size(), 1) { 
			int u = edge[i].second.first, v = edge[i].second.second;
			if (!uf.isSameSet(u, v)) { 
				uf.unionSet(u, v);
				ans += edge[i].first;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
