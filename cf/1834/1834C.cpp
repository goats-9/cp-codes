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
        string a, b;
        cin >> n >> a >> b;
        int a1 = 0, a2 = 0;
        f(i,0,n,1) {
            if (a[i] != b[i]) a1++;
            if (a[i] != b[n-i-1]) a2++;
        }
        if (a1 == 0) {cout << 0 << nl; continue;}
        if (a2 == 0) {cout << 2 << nl; continue;}
        int x = 2*a1 - (a1%2);
        int y = 2*a2 - 1 + (a2%2) ;
        cout << min(x, y) << nl;
	}
	return 0;
}
