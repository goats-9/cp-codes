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
#define N (int)3e5

int main() {
    ll n, m, x = 0, tot = 1, na = 1, t = 0, y = 1;
    cin >> n >> m;
    vi a(N + 1);
    f(i, 0, N + 1, 1) a[i] = i;
    f(i, 2, N + 1, 2) a[i] = 2;
    for (int i = 3; i*i <= N; i++) {
        if (a[i] < i) continue;
        for (int j = i*i; j <= N; j += i) a[j] = i;
    }
    f(i, 1, n + 1, 1) {
        tot = (tot*(m%MOD))%MOD;
        x = (x + tot)%MOD;
    }
    f(i, 1, n + 1, 1) { 
        y = lcm(y, (ll)a[i]);
        na = (na*((m/y)%MOD))%MOD;
        t = (t + na)%MOD;
    }
    cout << (x + MOD - t)%MOD << nl;
	return 0;
}
