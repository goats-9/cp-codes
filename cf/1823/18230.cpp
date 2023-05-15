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

int n, k;

void solve() {
    f(i,0,n+1,1) {
        if (k == (i*(i-1) + (n-i)*(n-i-1))/2) {
            cout << "YES\n";
            f(j,0,i,1) cout << "1 ";
            f(j,i,n,1) cout << "-1 ";
            cout << nl;
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
	int t;
	cin >> t;
    while (t--) { 
        cin >> n >> k;
        solve();
	}
	return 0;
}
