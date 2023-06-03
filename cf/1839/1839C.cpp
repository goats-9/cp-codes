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
        vi a(n);
        f(i,0,n,1) cin >> a[i];
        if (a.back()) {cout << "NO\n"; continue;} 
        reverse(all(a));
        cout << "YES\n";
        int i = 0;
        while (i < n) {
            int p = 0, q = 0;
            while (i + p < n && a[i + p] == 0) p++;
            i += p;
            while (i + q < n && a[i + q] == 1) q++;
            f(j,0,p+q-1,1) cout << "0 ";
            cout << q << ' ';
            i += q;
        }
        cout << nl;
	}
	return 0;
}
