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
    vi p, rank, sz;
    int numSets, maxSize;
public:
    UnionFind(int n) {
        p.assign(n, -1);
        rank.assign(n, 0);
        sz.assign(n, 1);
        numSets = n, maxSize = 1;
    }

    int findSet(int i) {return p[i] < 0 ? i : (p[i] = findSet(p[i]));}

    bool unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        p[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
        sz[x] += sz[y];
        numSets--;
        maxSize = max(maxSize, sz[x]);
        return true;
    }

    int getNumSets() {return numSets;}

    int getMaxSize() {return maxSize;}

};

int main() {
    int n, m;
    cin >> n >> m;
    V<P<ll, pii>> edges;
    UnionFind uf(n);
    f(i,0,m,1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.pb({w, {u, v}});
    }
    sort(all(edges));
    ll ans = 0;
    for (auto &[w, p] : edges) {
        auto &[u, v] = p;
        if (uf.unionSet(u, v)) ans += w;
    }
    if (uf.getNumSets() > 1) cout << "IMPOSSIBLE\n";
    else cout << ans << nl;
	return 0;
}
