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
        vi b(n-1);
        f(i,0,n-1,1) cin >> b[i];
        vvi a;
        int k = 0;
        while (k < n - 1) {
            vi c; c.pb(b[k]);
            while (k + 1 < n - 1 && b[k] <= b[k + 1]) {
                c.pb(b[k + 1]);
                k++;
            }
            k++;
            a.pb(c);
        }
        int sz = a.size();
        f(i,0,sz,1) {
            if (i == sz - 1) {
                cout << 0 << ' ';
                f(j,0,a[i].size(),1) cout << a[i][j] << ' '; 
            } else {
                int p = a[i].size();
                if (p == 1) cout << a[i][0] << ' ';
                else {
                    cout << 0 << ' ';
                    f(j,0,p-1,1) cout << a[i][j] << ' ';
                }
            }
        }
        cout << nl;
	}
	return 0;
}
