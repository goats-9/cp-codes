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

vvi adj;
vi mxlen, mxchild, mxlen2;

void dfs(int u, int p) {
    mxlen[u] = 0, mxlen2[u] = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (mxlen[u] < mxlen[v] + 1) {
            mxlen2[u] = mxlen[u];
            mxlen[u] = mxlen[v] + 1;
            mxchild[u] = v;
        } else if (mxlen2[u] < mxlen[v] + 1) {
            mxlen2[u] = mxlen[v] + 1;
        }
    }
}

void dfs2(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (mxchild[u] == v) {
            if (mxlen[v] < mxlen2[u] + 1) {
                mxlen2[v] = mxlen[v];
                mxlen[v] = mxlen2[u] + 1;
                mxchild[v] = u;
            } else {
                mxlen2[v] = max(mxlen2[v], mxlen2[u] + 1);
            }
        } else {
            mxlen2[v] = mxlen[v];
            mxlen[v] = mxlen[u] + 1;
            mxchild[v] = u;
        }
        dfs2(v, u);
    }
}

int main() {
    int n; cin >> n;
    adj.assign(n+1, vi());
    f(i,0,n-1,1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    mxlen.assign(n+1,0);
    mxchild.assign(n+1,0);
    mxlen2.assign(n+1,0);
    dfs(1, -1); 
    dfs2(1, -1);
    f(i,1,n+1,1) cout << mxlen[i] << ' ';
    cout << nl;
	return 0;
}
