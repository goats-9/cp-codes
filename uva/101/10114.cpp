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
    int m, r;
    double p, d;
	while (cin >> m >> p >> d >> r && m >= 0) { 
        int ans = 0;
        V<P<int, double>> dep(r);
        f(i,0,r,1) cin >> dep[i].first >> dep[i].second;
        double owe = d, cur = (d+p)*(1-dep[0].second), pay = d/m;
        while (owe >= cur && ans < m) {
            ++ans;
            int pos = upper_bound(all(dep), mp(ans, 1.1)) - dep.begin() - 1;
            owe -= pay, cur *= (1 - dep[pos].second);
        }
        cout << ans << " month";
        if (ans != 1) cout << "s\n";
        else cout << "\n";
	}
	return 0;
}
