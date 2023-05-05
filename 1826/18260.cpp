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
	int t, n, x;
	cin >> t;
    while (t--) { 
        cin >> n;
        vi a(n+1);
        f(i,0,n,1) {
            cin >> x;
            ++a[x];
        }
        vi b(n+1);
        b[0] = a[0];
        f(i,1,n+1,1) b[i] = b[i-1]+a[i];
        bool fl = false;
        f(i,0,n+1,1) {
            if (a[i] && n - b[i] >= i && b[n - b[i]] == b[i]) {cout << n - b[i] << nl; fl = true; break;} 
        }
        if (!fl) cout << -1 << nl;
	}
	return 0;
}
