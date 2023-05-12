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
        vll a(n+1);
        f(i,1,n+1,1) cin >> a[i];
        sort(all(a));
        f(i,1,n+1,1) a[i] += a[i-1];
        int l = 0, r = n - k;
        ll mx = 0;
        f(i,0,k+1,1) {
            mx = max(mx, a[r] - a[l]);
            l+=2, r++;
        }
        cout << mx << nl;
	}
	return 0;
}
