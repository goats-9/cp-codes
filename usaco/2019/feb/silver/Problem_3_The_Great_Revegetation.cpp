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

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vi color(n, -1);
    V<V<P<int, bool>>> adj(n);
    f(i,0,m,1) {
        char ch;
        int u, v;
        cin >> ch >> u >> v;
        adj[--u].pb({--v, ch == 'S'});
        adj[v].pb({u, ch == 'S'});
    }
    int cmp = 0;
    f(i,0,n,1) {
        if (color[i] != -1) continue;
        ++cmp;
        queue<P<int, bool>> q; q.push({i, true});
        while (!q.empty()) {
            P<int, bool> u = q.front(); q.pop();
            color[u.first] = u.second;
            for (auto v : adj[u.first]) {
                bool type = v.second ? u.second : !u.second;
                if (color[v.first] == -1) {
                    q.push({v.first, type});
                }
                else if (color[v.first] == !type) {
                    cout << "0\n"; return 0;
                }
            }
        }
    }
    cout << 1;
    f(i,0,cmp,1) cout << 0;
    cout << nl;
	return 0;
}
