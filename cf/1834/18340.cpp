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
	int t;
	cin >> t;
	while (t--) { 
        int n;
        cin >> n;
        int p = 0, q = 0;
        f(i,0,n,1) {
            int x;
            cin >> x;
            if (x == -1) p++;
            else q++;
        }
        if (q >= p) {
            if (p%2) cout << 1 << nl;
            else cout << 0 << nl;
        } else {
            int k = ((p-q)>>1) + ((p-q)&1);
            cout << k + ((p - k) % 2) << nl;
        }
	}
	return 0;
}
