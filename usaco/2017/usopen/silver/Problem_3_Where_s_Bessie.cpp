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

V<string> a;
int n;
V<P<pii, pii>> pcl;

bool isgood(int x1, int y1, int x2, int y2) {
    vi ctr(26);
    f(i,x1,x2+1,1) f(j,y1,y2+1,1) ctr[a[i][j]-'A'] = 1;
    int ans = 0;
    f(i,0,26,1) if (ctr[i]) ++ans;
    if (ans != 2) return false;
    ctr.assign(26, 0);
    V<V<bool>> vis(n, V<bool>(n, false));
    f(i,x1,x2+1,1) f(j,y1,y2+1,1) {
        if (vis[i][j]) continue;
        char ch = a[i][j]; ++ctr[ch-'A'];
        queue<pii> q; q.push({i,j});
        vis[i][j] = true;
        while (!q.empty()) {
            auto &[u, v] = q.front(); q.pop();
            if (u > x1 && !vis[u-1][v] && a[u-1][v] == ch) {
                vis[u-1][v] = true;
                q.push({u-1,v});
            }
            if (u < x2 && !vis[u+1][v] && a[u+1][v] == ch) {
                vis[u+1][v] = true;
                q.push({u+1,v});
            }
            if (v > y1 && !vis[u][v-1] && a[u][v-1] == ch) {
                vis[u][v-1] = true;
                q.push({u,v-1});
            }
            if (v < y2 && !vis[u][v+1] && a[u][v+1] == ch) {
                vis[u][v+1] = true;
                q.push({u,v+1});
            }
        }
    }
    int oc = 0, mc = 0;
    f(i,0,26,1) oc += (ctr[i] == 1), mc += (ctr[i] > 1);
    return oc && mc;
}

bool subset(int i, int j) {
    return pcl[i].first.first >= pcl[j].first.first
    && pcl[i].first.second >= pcl[j].first.second
    && pcl[i].second.first <= pcl[j].second.first
    && pcl[i].second.second <= pcl[j].second.second;
}

bool ismaximal(int i) {
    f(j,0,pcl.size(),1) {
        if (j == i) continue;
        if (subset(i, j)) return false;
    }
    return true;
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    a.assign(n, "");
    f(i,0,n,1) cin >> a[i];
    int ans = 0;
    vvi cover(n, vi(n, 0));
    f(x1,0,n,1) f(y1,0,n,1) f(x2,x1,n,1) f(y2,y1,n,1) if (isgood(x1, y1, x2, y2)) pcl.pb({{x1,y1}, {x2,y2}});
    f(i,0,pcl.size(),1) ans += ismaximal(i);
    cout << ans << nl;
	return 0;
}
