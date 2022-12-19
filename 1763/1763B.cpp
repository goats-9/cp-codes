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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7
#define INF (ll)1e18

int main() {
    ll t, n, k;
    cin >> t;
    while (t--) { 
        cin >> n >> k;
        ll dmg = 0;
        V<pll> hp(n);
        f(i, 0, n, 1) cin >> hp[i].second;
        f(i, 0, n, 1) cin >> hp[i].first;
        sort(all(hp));
        int j = 0;
        while (k > 0) { 
            dmg += k;
            while (j < n && dmg >= hp[j].second) ++j;
            if (j == n) break;
            k -= hp[j].first;
        }
        if (j == n) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
