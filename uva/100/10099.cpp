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
#define INF 2e9

class UnionFind {
    vi p, rank;

public:
    UnionFind(int n) {
        p.assign(n+1,0);
        rank = p;
        f(i,0,n+1,1) p[i] = i; 
    }

    int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}

    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
        }
    }
};

int main() {
    int n, r, c1, c2, p, s, d, t, tc = 0;
    while (cin >> n >> r && n) {
        V<P<int, pii>> el;
        f(i,0,r,1) {
            cin >> c1 >> c2 >> p;
            el.pb(mp(p, pii(c1, c2)));
        }
        sort(rall(el));
        cin >> s >> d >> t;
        int b = 1e9, j = 0;
        UnionFind uf(n);
        while (!uf.isSameSet(s, d)) {
            b = min(b, el[j].first);
            uf.unionSet(el[j].second.first, el[j].second.second);
            j++;
        }
        cout << "Scenario #" << ++tc << "\nMinimum Number of Trips = "; 
        cout << (int)ceil(t/(b-1.0)) << nl << nl;
    }
	return 0;
}
