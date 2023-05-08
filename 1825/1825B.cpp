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
	int t, n, m;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        vi a(n*m);
        f(i,0,n*m,1) cin >> a[i];
        sort(all(a));
        ll x = min(n, m), y = max(n, m);
        ll p = a[n*m-1] - a[0], q = a[n*m-2] - a[0], r = a[n*m-1] - a[1];
        cout << max(p*x*(y-1) + q*(x-1), p*x*(y-1) + r*(x-1)) << nl;
	}
	return 0;
}
