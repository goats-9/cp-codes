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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int t, l, r, x, a, b;
    scanf("%d", &t);
    while (t--) { 
        cin >> l >> r >> x >> a >> b;
        if (a == b) cout << 0 << nl;
        else if (abs(a - b) >= x) cout << 1 << nl;
        else {
            if (a - l < x && r - a < x) cout << -1 << nl;
            else { 
                if (r - a < x) { 
                    if (b - l >= x) cout << 2 << nl;
                    else if (r - b >= x) cout << 3 << nl;
                    else cout << -1 << nl;
                } else if (a - l < x) { 
                    if (r - b >= x) cout << 2 << nl;
                    else if (b - l >= x) cout << 3 << nl;
                    else cout << -1 << nl;
                } else { 
                    if (r - b >= x || b - l >= x) cout << 2 << nl;
                    else cout << -1 << nl;
                }
            }
        }
	}
	return 0;
}
