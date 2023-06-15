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
        vi a;
        bool fl = false;
        f(i,0,n,1) {
            int x;
            cin >> x;
            if (a.empty()) {
                a.pb(x);
                cout << 1;
                continue;
            }
            if (!fl) {
                if (x < a.back()) {
                    if (x <= a.front()) fl = true;
                    else {
                        cout << 0;
                        continue;
                    }
                }
                a.pb(x);
                cout << 1;
            } else {
                if (x < a.back()) cout << 0;
                else {
                    if (x > a.front()) cout << 0;
                    else {
                        cout << 1;
                        a.pb(x);
                    }
                }
            }
        }
        cout << nl;
	}
	return 0;
}
