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
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = n*m + 1;
    while (l < r) { 
        ll g = (l+r)/2;
        ll p = 0;
        f(i, 1, n + 1, 1) p += min(m, (g-1)/i);
        if (p < k) l = g + 1;
        else r = g;
    }
    cout << l - 1 << nl;
	return 0;
}
