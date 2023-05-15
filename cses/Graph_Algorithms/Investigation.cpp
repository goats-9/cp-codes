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
#define MOD (ll)1000000007
#define INF (ll)1e17
 
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vll dist(n, INF); dist[0] = 0;
    vll num(n); num[0] = 1;
    vll mxflt(n), mnflt(n);
    V<V<pll>> adj(n, V<pll>());
    f(i,0,m,1) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].pb(pll(b, c));
    }
    set<pll> st;
    f(i,0,n,1) st.emplace(pll(dist[i],i));
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w > dist[v]) continue;
            else if (dist[u] + w == dist[v]) {
                num[v] = (num[v] + num[u]) % MOD;
                mxflt[v] = max(mxflt[v], mxflt[u] + 1);
                mnflt[v] = min(mnflt[v], mnflt[u] + 1);
            } else {
                st.erase(st.find(pll(dist[v], v)));
                dist[v] = dist[u] + w;
                st.emplace(pll(dist[v], v));
                num[v] = num[u];
                mxflt[v] = mxflt[u] + 1;
                mnflt[v] = mnflt[u] + 1;
            }
        }
    }
    cout << dist[n-1] << ' ' << num[n-1] << ' ' << mnflt[n-1] << ' ' << mxflt[n-1] << nl;
}