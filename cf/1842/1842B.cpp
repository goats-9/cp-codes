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
        int n, x;
        cin >> n >> x;
        vvi a(3, vi(n+1));
        f(i,0,3,1) f(j,1,n+1,1) cin >> a[i][j];
        f(i,0,3,1) f(j,1,n+1,1) a[i][j] |= a[i][j-1];
        int k = 0;
        f(i,0,3,1) {
            f(j,0,n+1,1) {
                if ((a[i][j] & x) == a[i][j]) k |= a[i][j];
                else break;
            }
        }
        if (k == x) cout << "Yes\n";
        else cout << "No\n";
	}
	return 0;
}
