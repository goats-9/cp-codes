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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7
#define N (int)1e5

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vi c(n + 1);
    V<bool> isclr(N + 1, false);
    f(i, 1, n + 1, 1) {cin >> c[i]; isclr[c[i]] = true;}
    vvi adj(n + 1, vi());
    V<set<int>> cadj(N + 1, set<int>());
    f(i, 0, m, 1) { 
        cin >> x >> y;
        adj[x].pb(y), adj[y].pb(x);
    }
    f(i, 1, n + 1, 1) { 
        int clr = c[i];
        f(j, 0, adj[i].size(), 1) { 
            int v = adj[i][j];
            if (clr != c[v]) cadj[clr].insert(c[v]);
        }
    }
    int mx = -1, mxclr = -1;
    f(i, 1, N + 1, 1) if (isclr[i] && mx < (int)cadj[i].size()) mx = cadj[i].size(), mxclr = i;
    cout << mxclr << nl;
	return 0;
}
