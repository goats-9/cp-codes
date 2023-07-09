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
public:
    UnionFind(int n) {
        p.assign(n, -1);
        rank.assign(n, 0);
        sz.assign(n, 1);
    }

    int findSet(int i) {return p[i] < 0 ? i : (p[i] = findSet(p[i]));}

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        p[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
        sz[x] += sz[y];
    }

    int queryAns(int i) {return sz[findSet(i)] - 1;}
};

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    V<P<int, pii>> a;
    f(i,0,n-1,1) {
        int u, v, w;
        cin >> u >> v >> w;
        a.pb({w, {u, v}});
    }
    V<P<pii, int>> qr;
    f(i,0,q,1) {
        int k, v;
        cin >> k >> v;
        qr.pb({{k, v}, i});
    }
    vi ans(q);
    sort(rall(a));
    sort(rall(qr));
    UnionFind uf(n+1);
    int j = 0;
    f(i,0,q,1) {
        auto &[k, x] = qr[i].first;
        int idx = qr[i].second;
        while (a[j].first >= k) {
            auto &[u, v] = a[j].second;
            uf.unionSet(u, v);
            j++;
        }
        ans[idx] = uf.queryAns(x);
    }
    f(i,0,q,1) cout << ans[i] << nl;
	return 0;
}
