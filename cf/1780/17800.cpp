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
        int x;
        V<pii> o, e;
        f(i, 0, n, 1) { 
            cin >> x;
            if (x%2) o.pb(pii(x,i+1));
            else e.pb(pii(x,i+1));
        }
        if ((int)o.size() >= 3) { 
            cout << "YES\n";
            cout << o[0].second << ' ' << o[1].second << ' ' << o[2].second << nl;
        } else if ((int)o.size() >= 1 && e.size() >= 2) { 
            cout << "YES\n";
            cout << o[0].second << ' ' << e[0].second << ' ' << e[1].second << nl;
        } else cout << "NO\n";
	}
	return 0;
}
