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
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n;
    cin >> n;
    V<string> a(n+2);
    V<V<bool>> vis(n+2, V<bool> (n+2, false));
    V<pii> blob;
    a.front() = a.back() = string(n+2, '.');
    f(i,1,n+1,1) {
        cin >> a[i];
        a[i] = '.' + a[i] + '.';
    }
    f(i,1,n+1,1) {
        f(j,1,n+1,1) {
            if (a[i][j] == '.' || vis[i][j]) continue;
            int ar = 0, per = 0;
            queue<pii> q; q.push({i, j});
            vis[i][j] = true;
            while (!q.empty()) {
                auto &[u, v] = q.front(); q.pop();
                if (a[u-1][v] == '.') ++per;
                if (a[u][v-1] == '.') ++per;
                if (a[u][v+1] == '.') ++per;
                if (a[u+1][v] == '.') ++per;
                ++ar;
                if (a[u+1][v] == '#' && !vis[u+1][v]) {
                    q.push({u+1, v});
                    vis[u+1][v] = true;
                }
                if (a[u-1][v] == '#' && !vis[u-1][v]) {
                    q.push({u-1, v});
                    vis[u-1][v] = true;
                }
                if (a[u][v+1] == '#' && !vis[u][v+1]) {
                    q.push({u, v+1});
                    vis[u][v+1] = true;
                }
                if (a[u][v-1] == '#' && !vis[u][v-1]) {
                    q.push({u, v-1});
                    vis[u][v-1] = true;
                }
            }
            blob.pb({ar, per});           
        }
    }
    sort(all(blob), [&](pii &a, pii &b){
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    cout << blob.front().first << ' ' << blob.front().second << nl;
	return 0;
}
