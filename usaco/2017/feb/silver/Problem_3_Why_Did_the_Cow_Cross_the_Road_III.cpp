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
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int n, k, r, x1, y1, x2, y2;
    cin >> n >> k >> r;
    set<P<pii, pii>> st;
    f(i,0,r,1) {
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --x2, --y1, --y2;
        st.insert({{x1,y1},{x2,y2}});
        st.insert({{x2,y2},{x1,y1}});
    }
    int cmp = 0;
    int vis[n][n];
    memset(vis, -1, sizeof(vis));
    f(i,0,n,1) f(j,0,n,1) {
        if (vis[i][j] != -1) continue;
        ++cmp;
        queue<pii> q; q.push({i,j});
        vis[i][j] = cmp;
        while (!q.empty()) {
            auto &[u, v] = q.front(); q.pop();
            if (u > 0 && vis[u-1][v] == -1 && st.find({{u,v},{u-1,v}}) == st.end()) {
                vis[u-1][v] = cmp;
                q.push({u-1,v});
            }
            if (u < n - 1 && vis[u+1][v] == -1 && st.find({{u,v},{u+1,v}}) == st.end()) {
                vis[u+1][v] = cmp;
                q.push({u+1,v});
            }
            if (v > 0 && vis[u][v-1] == -1 && st.find({{u,v},{u,v-1}}) == st.end()) {
                vis[u][v-1] = cmp;
                q.push({u,v-1});
            }
            if (v < n - 1 && vis[u][v+1] == -1 && st.find({{u,v},{u,v+1}}) == st.end()) {
                vis[u][v+1] = cmp;
                q.push({u,v+1});
            }
        }
    }
    V<pii> cows(k);
    f(i,0,k,1) {
        cin >> cows[i].first >> cows[i].second;
        --cows[i].first, --cows[i].second;
    }
    int ans = 0;
    f(i,0,k,1) f(j,i+1,k,1) if (vis[cows[i].first][cows[i].second] != vis[cows[j].first][cows[j].second]) ++ans;
    cout << ans << nl;
	return 0;
}
