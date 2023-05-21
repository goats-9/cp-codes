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
#define N 1e6+10

int main() {
    vi spf(N);
    f(i,0,N,1) spf[i] = i;
    f(i,2,N,2) spf[i] = 2;
    for (int i = 3; i*i <= N; i++) {
        if (spf[i] < i) continue;
        for (int j = i*i; j <= N; j += i) spf[j] = min(spf[j], i);
    }
    int n; cin >> n;
    f(i,0,n,1) {
        int x;
        cin >> x;
        mii pctr;
        while (x != 1) {
            ++pctr[spf[x]];
            x /= spf[x];
        }
        ll ans = 1;
        for (auto &[u, v]: pctr) ans *= (v+1);
        cout << ans << nl;
    }
	return 0;
}
