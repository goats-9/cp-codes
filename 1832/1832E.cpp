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
#define MOD (ll)998244353

int main() {
    ll n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;
    vll a(n), org(n);
    a[0] = a1; org[0] = a1;
    f(i,1,n,1) org[i] = (x*org[i-1]+y)%m;
    f(i,1,n,1) a[i] = (org[i]+a[i-1])%MOD;
    vvll b(n, vll(k));
    b[0][0] = a[0];
    f(i,1,n,1) b[i][0] = (b[i-1][0] + a[i])%MOD;
    f(j,1,k,1) {
        b[0][j] = 0;
        f(i,1,n,1) b[i][j] = (b[i-1][j-1] + b[i-1][j])%MOD;
    }
    ll c = 0;
    f(i,0,n,1) c ^= (b[i][k-1]*(i+1));
    cout << c << nl;
	return 0;
}
