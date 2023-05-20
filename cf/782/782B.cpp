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

vll x, v;
ll n;

bool good(double t) {
    double xl = -1e18, xr = 1e18;
    f(i,0,n,1) {
        xl = max(x[i]-v[i]*t, xl);
        xr = min(x[i]+v[i]*t, xr);
    }
    return xl <= xr;
}

int main() {
    cin >> n;
    x.assign(n, 0), v.assign(n, 0);
    f(i,0,n,1) cin >> x[i];
    f(i,0,n,1) cin >> v[i];
    double l = 0, r = 1e9;
    f(i,0,100,1) {
        double t = (l+r)/2.0;
        if (good(t)) r = t;
        else l = t;
    }
    cout << setprecision(12) << r << nl;
	return 0;
}
