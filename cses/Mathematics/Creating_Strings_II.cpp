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
#define N 1000010

ll modexp(ll a, ll b) {
    if (b == 0) return 1;
    ll y = modexp(a, (b>>1));
    ll z = y*y%MOD1;
    if (b%2) z = z*a%MOD1;
    return z;
}

int main() {
    vll fac(N), invfac(N);
    fac[0] = 1;
    f(i,1,N,1) fac[i] = (i*fac[i-1])%MOD1;
    invfac[N-1] = modexp(fac[N-1],MOD1-2);
    for (int i = N - 2; i >= 0; i--) invfac[i] = invfac[i+1]*(i+1)%MOD1;
    string s;
    cin >> s;
    vi a(26);
    int sz = 0;
    for (char ch : s) ++a[ch-'a'], ++sz;
    ll ans = fac[sz];
    f(i,0,26,1) ans = ans*invfac[a[i]]%MOD1;
    cout << ans << nl;
	return 0;
}
