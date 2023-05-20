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
    int n, m, a, b;
    cin >> n >> m;
    vvi adj(n+1, vi()), adjrev(n+1, vi());
    f(i,0,m,1) {
        cin >> a >> b;
        adj[a].pb(b);
        adjrev[b].pb(a);
    }
    V<bool> vis(n+1, false), visr(n+1, false);
    queue<int> q; q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    q.push(1);
    visr[1] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adjrev[u]) {
            if (!visr[v]) {
                visr[v] = true;
                q.push(v);
            }
        }
    }
    f(i,1,n+1,1) {
        if (!vis[i]) {
            cout << "NO\n1 " << i << nl;
            return 0;
        } else if (!visr[i]) {
            cout << "NO\n" << i << " 1\n";
            return 0;
        }
    }
    cout << "YES\n";
	return 0;
}
