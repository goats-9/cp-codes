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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    f(i,0,n,1) cin >> a[i];
    f(i,0,m,1) cin >> b[i];
    int r = 0;
    f(i,0,n,1) {
        auto it = lower_bound(all(b), a[i]);
        if (it == b.begin()) r = max(*b.begin()-a[i], r);
        else if (it == b.end()) r = max(a[i]-b.back(), r);
        else {
            int pos = it - b.begin();
            r = max(min(abs(a[i]-b[pos]), abs(a[i]-b[pos-1])), r);
        }
    }
    cout << r << nl;
	return 0;
}
