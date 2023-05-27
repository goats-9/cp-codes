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
    bool operator< (const Edge &e) const {return w < e.w;}
};

class UnionFind {
    vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0);
        rank = p;
        f(i,0,n,1) p[i] = i;
    }

    int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}

    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x == y) return;
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
    }
};

int main() {
    int c, s, q, tc = 0;
    while (cin >> c >> s >> q && c) {
        if (tc++) cout << nl;
        V<Edge> edge(s);
        f(i,0,s,1) cin >> edge[i].u >> edge[i].v >> edge[i].w;
        sort(all(edge));
        cout << "Case #" << tc << nl; 
        f(i,0,q,1) {
            int u, v;
            int k = 0, ans = 0;
            UnionFind uf(c+1);
            cin >> u >> v;
            while (!uf.isSameSet(u, v) && k < s) {
                uf.unionSet(edge[k].u, edge[k].v);
                ans = edge[k].w;
                k++;
            }
            if (uf.isSameSet(u, v)) cout << ans << nl;
            else cout << "no path\n";
        }
    }
	return 0;
}
