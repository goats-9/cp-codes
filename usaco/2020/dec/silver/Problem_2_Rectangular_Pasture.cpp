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

bool cmp(pii &x, pii &y) {return x.second < y.second;}

int main() {
    int n; cin >> n;
    V<pii> a(n);
    mii red_x, red_y;
    f(i,0,n,1) cin >> a[i].first >> a[i].second;
    sort(all(a));
    f(i,0,n,1) red_x[a[i].first] = i;
    sort(all(a), cmp);
    f(i,0,n,1) red_y[a[i].second] = i;
    for (auto &[x, y]: a) x = red_x[x], y = red_y[y];
    sort(all(a));
    vvll below(n, vll(n+1)), above(n, vll(n+1));
    f(i,0,n,1) {
        int curr = a[i].second;
        f(j,1,n+1,1) {
            below[curr][j] = below[curr][j-1] + (a[j-1].second < curr);
            above[curr][j] = above[curr][j-1] + (a[j-1].second > curr);
        }
    }
    ll ans = 0;
    f(i,0,n,1) {
        f(j,i+1,n,1) {
            int down = min(a[i].second, a[j].second), up = max(a[i].second, a[j].second);
            ans += (1 + below[down][j+1] - below[down][i])*(1 + above[up][j+1] - above[up][i]);
        }
    }
    cout << ans + n + 1 << nl;
	return 0;
}
