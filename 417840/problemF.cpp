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

int main() {
    ll n, m, x;
    multiset<ll> vids;
    cin >> n >> m;
    ll ans = 0;
    f(i, 0, n, 1) { 
        cin >> x;
        ans += x;
        vids.insert(x);
    }
    ll sz = m;
    while (!vids.empty()) { 
        auto it = vids.upper_bound(sz);
        if (it == vids.begin()) {
            ++ans, sz = m; 
            continue;
        }
        --it;
        sz = m - *it;
        vids.erase(it);
    }
    cout << ans + 1 << nl;
	return 0;
}
