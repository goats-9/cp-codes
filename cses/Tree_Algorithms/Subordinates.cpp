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
	int n, b;
    cin >> n;
    vvi adj(n+1, vi());
    vi indeg(n+1);
    f(i,2,n+1,1) {
        cin >> b;
        adj[i].pb(b);
        ++indeg[b];
    }
    vi ans(n+1);
    queue<int> q;
    f(i,1,n+1,1) if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            --indeg[v];
            if (!indeg[v]) q.push(v);
            ans[v] += (ans[u] + 1);
        }
    }
    f(i,1,n+1,1) cout << ans[i] << ' ';
    cout << nl;
	return 0;
}
