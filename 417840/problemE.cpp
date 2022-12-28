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
 
void solve() { 
    int n; cin >> n;
    vi a(n, -1);
    f(i, 1, n, 2) cin >> a[i];
    V<bool> elem(n + 1, false);
    f(i, 1, n, 2) {
        if (elem[a[i]]) {cout << -1 << nl; return; }
        elem[a[i]] = true;
    }
    V<pii> vals;
    set<int> pos;
    f(i, 1, n, 2) vals.pb(pii(a[i], i - 1));
    sort(rall(vals));
    int sz = vals.size(), j = 0;
    for (int i = n; i > 0; i--) { 
        if (elem[i]) continue;
        while (j < sz && vals[j].first >= i) {
            pos.insert(vals[j].second);
            ++j;
        }
        if (pos.empty()) {cout << -1 << nl; return;}
        int k = *pos.rbegin();
        if (i > a[k + 1]) {cout << -1 << nl; return;}
        a[k] = i;
        pos.erase(k);
        elem[i] = true;
    }
    f(i, 0, n, 1) cout << a[i] << " ";
    cout << nl; return;
}
 
int main() {
	int t;
    cin >> t;
    while (t--) { 
        solve();
	}
	return 0;
}