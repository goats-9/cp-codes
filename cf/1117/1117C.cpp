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
#define INF 1e18

ll a1, b1, a2, b2, n;
string s;
V<pll> wind;

bool good(ll x) {
    pll mul = wind.back();
    pll rem = wind[x%n];
    pll wind_move((x/n)*mul.first + rem.first, (x/n)*mul.second + rem.second);
    return abs(a2 - a1 - wind_move.first) + abs(b2 - b1 - wind_move.second) <= x;
} 

int main() {
    cin >> a1 >> b1 >> a2 >> b2 >> n >> s;
    wind.assign(n+1, pll(0,0));
    f(i,0,n,1) {
        wind[i+1] = wind[i];
        if (s[i] == 'U') wind[i+1].second++;
        if (s[i] == 'D') wind[i+1].second--;
        if (s[i] == 'L') wind[i+1].first--;
        if (s[i] == 'R') wind[i+1].first++;
    }
    ll l = 0, r = INF;
    while (r > l + 1) {
        ll m = (l+r)/2;
        if (good(m)) r = m;
        else l = m;
    }
    if (r > INF/2) cout << -1 << nl;
    else cout << r << nl;
	return 0;
}
