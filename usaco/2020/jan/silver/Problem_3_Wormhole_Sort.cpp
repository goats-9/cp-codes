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

struct Edge {
    int u, v, w;
    bool operator< (const Edge &e) const {
        return w < e.w;
    }
};

class UnionFind {
    private: vi p, rank;
    public:
        
        UnionFind(int n) {
            p.assign(n,0);
            rank.assign(n,0);
            f(i,0,n,1) p[i] = i;
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

        void unionSet(int i, int j) {
            int x = findSet(i), y = findSet(j);
            if (x != y) {
                if (rank[x] < rank[y]) {
                    p[y] = x;
                    rank[x]++;
                } else {
                    if (rank[x] == rank[y]) p[y] = x;
                    else p[x] = y;
                    rank[y]++;
                }
            }
        }
};

int main() {
	int n, m;
    ifstream ip("wormsort.in");
    ofstream op("wormsort.out");
    ip >> n >> m;
    vi a(n+1);
    UnionFind uf(n+1);
    V<Edge> edge(m);
    f(i,1,n+1,1) ip >> a[i];
    V<bool> vis(n+1, false);
    V<pii> unionPairs;
    f(i,1,n+1,1) {
        int u = i;
        vi cyc;
        while (!vis[u]) {
            cyc.pb(u);
            vis[u] = true;
            u = a[u];
        }
        int sz = cyc.size();
        f(i,0,sz-1,1) unionPairs.pb(pii(cyc[i], cyc[i+1]));
    }
    int usz = unionPairs.size();
    f(i,0,m,1) ip >> edge[i].u >> edge[i].v >> edge[i].w;
    sort(rall(edge));
    int ans = -1, l = 0, el = 0;
    while (l < usz && el < m) {
        ans = edge[el].w;
        uf.unionSet(edge[el].u, edge[el].v);
        el++;
        while (l < usz && uf.isSameSet(unionPairs[l].first, unionPairs[l].second)) l++;
    }
    op << ans << nl;
    ip.close(); op.close();
	return 0;
}
