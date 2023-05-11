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
#define MOD (int)1e9 + 7
#define INF (int)1e9

int main() {
    string s;
    int n, m, x;
    while (cin >> s){
        cin >> n >> m;
        V<V<pii>> adj(m*n);
        f(i,0,n-1,1) {
            f(j,0,m,1) {
                f(k,0,m,1) {
                    cin >> x;
                    adj[m*i + j].pb(pii(m*(i+1)+k, x));
                }
            }
        }
        vi dist(m*n, INF);
        queue<int> q;
        f(i,0,m,1) {
            dist[i] = 0;
            q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (pii e: adj[u]) {
                int v = e.first;
                int w = e.second;
                if (dist[u] + w >= dist[v]) continue;
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
        int ans = INF;
        f(i,m*(n-1),m*n,1) ans = min(ans, dist[i]);
        cout << s << nl << ans + ((n-1)<<1) << nl;
    }
	return 0;
}
