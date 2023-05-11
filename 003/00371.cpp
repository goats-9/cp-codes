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
    ll x, y;
    while (cin >> x >> y && x) {
        ll ctr = 0, mx = 0;
        for (ll j = min(x,y); j <= max(x,y); j++) {
            ll i = j;
            ll p = 0;
            while (1) {
                if (i%2) i = 3*i + 1;
                else i /= 2;
                ++p;
                if (i == 1) break;
            }
            if (ctr < p) ctr = p, mx = j;
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", min(x,y), max(x,y), mx, ctr);
    }
	return 0;
}
