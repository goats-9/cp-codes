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
#define MOD (int)1e9 + 7

int main() {
	int t, n, k;
	cin >> t;
    while (t--) { 
        cin >> n >> k;
        vll a(n);
        f(i,0,n,1) cin >> a[i];
        int l = 0, ans = 0;
        while (l < n) {
            int p = 0;
            while (l + p + 1 < n && (a[l+p] < 2*a[l+p+1])) ++p;
            if (p >= k) ans += (p - k + 1);
            l += p + 1;
        }
        cout << ans << nl;
	}
	return 0;
}
