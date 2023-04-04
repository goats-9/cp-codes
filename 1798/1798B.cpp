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
	int t, m, n, x;
	cin >> t;
    while (t--) { 
        cin >> m;
        mii last;
        f(i,0,m,1) {
            cin >> n;
            f(j,0,n,1) {
                cin >> x;
                last[x] = i;
            }
        }
        vi day(m,-1);
        for (auto e: last) {
            day[e.second] = e.first;
        }
        bool fl = true;
        f(i,0,m,1) {
            if (day[i] == -1) {
                fl = false; break;
            }
        }
        if (fl) {
            f(i,0,m,1) cout << day[i] << ' ';
            cout << nl;
        } else cout << -1 << nl;
	}
	return 0;
}
