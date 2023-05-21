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
    vi spf(N, 0);
    f(i,0,N,1) spf[i] = i;
    f(i,2,N,2) spf[i] = 2;
    for (int i = 3; i*i <= N; i++) {
        if (spf[i] < i) continue;
        for (int j = i*i; j <= N; j += i) spf[j] = min(spf[j], i);
    }
    vi cnt(N), occ(N);
    int n, x; cin >> n;
    f(i,0,n,1) {
        cin >> x;
        if (occ[x] > 1) continue;
        occ[x]++;
        set<int> fac;
        fac.insert(1);
        while (x != 1) {
            vi newfac;
            for (auto y : fac) newfac.pb(y*spf[x]);
            fac.insert(all(newfac));
            x /= spf[x];
        }
        for (auto y : fac) ++cnt[y];
    }
    int mx = 1;
    f(i,1,N,1) if (cnt[i] > 1) mx = i;
    cout << mx << nl;
	return 0;
}
