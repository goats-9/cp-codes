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
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
	int t, a, b;
    cin >> t >> a >> b;
    bool vis[t+1][2];
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push(pii(0,0)); vis[0][0] = 1;
    int mx = 0;
    while (!q.empty()) {
        auto [u, fl] = q.front(); q.pop();
        if (!vis[u>>1][1] && !fl) {
            vis[u>>1][1] = true;
            q.push(pii(u>>1, 1));
            mx = max(mx, u>>1);
        }
        if (u + a <= t && !vis[u + a][fl]) {
            vis[u + a][fl] = true;
            q.push(pii(u + a, fl));
            mx = max(mx, u + a);
        }
        if (u + b <= t && !vis[u + b][fl]) {
            vis[u + b][fl] = true;
            q.push(pii(u + b, fl));
            mx = max(mx, u + b);
        }
    }
    cout << mx << nl;
	return 0;
}
