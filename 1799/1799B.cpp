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
        set<pii> a;
        V<pii> moves;
        f(i,0,n,1) {
            cin >> x;
            a.insert(pii(x,i+1));
        }
        if ((*(a.begin())).first == (*(--a.end())).first) {
            cout << 0 << nl;
            continue;
        }
        if ((*(a.begin())).first == 1 && (*(--a.end())).first > 1) {
            cout << -1 << nl; 
            continue;
        }
        while ((*(a.begin())).first != (*(--a.end())).first) {
            pii x = *(a.begin()), y = *(--a.end());
            a.erase(--a.end());
            while (y.first > x.first) {
                y.first = (int)ceil(y.first*1.0/x.first);
                moves.pb(pii(y.second,x.second));
            }
            a.insert(y);
        }
        cout << moves.size() << nl;
        for (pii x : moves) cout << x.first << ' ' << x.second << nl;
	}
	return 0;
}
