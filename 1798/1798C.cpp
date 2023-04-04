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
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        vll a(n), b(n);
        f(i,0,n,1) cin >> a[i] >> b[i];
        int i = 0, ctr = 0;
        while (i < n) {
            ll l = b[i], r = a[i]*b[i];
            int k = 1;
            while (i + k < n) {
                l = lcm(l, b[i+k]), r = gcd(r,a[i+k]*b[i+k]);
                if (r%l) break;
                k++;
            }
            i += k;
            ctr++;
        }
        cout << ctr << nl;
	}
	return 0;
}
