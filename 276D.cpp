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
#define LSOne(s) (s & (-s))

int main() {
    ll l, r;
    cin >> l >> r;
    if (l == r) {cout << 0 << nl; return 0;}
    ll x = 1LL<<(63 - __builtin_clzll(r));
    while (!(l < x && x <= r))
    {
        r -= x, l -= x;
        x = 1LL<<(63 - __builtin_clzll(r));
    }
    cout << (x<<1LL) - 1 << nl;
	return 0;
}
