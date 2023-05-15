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
#define N 200010

int main() {
    int t, n, k, x; cin >> t;
    while (t--) { 
        cin >> n;
        map<int, vi> a;
        f(i, 0, n, 1) { 
            cin >> k;
            f(j, 0, k, 1) { 
                cin >> x;
                a[x].pb(i);
            }
        }
        V<bool> comm(n, false);
        for (auto e : a) {
            int m = e.second.size();
            if (m == 1) comm[e.second[0]] = true;
        }
        bool fl = false;
        f(i, 0, n, 1) if (!comm[i]) {fl = true; break;}
        if (fl) cout << "Yes\n";
        else cout << "No\n";
	}
	return 0;
}
