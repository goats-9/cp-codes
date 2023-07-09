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
#define INF 1e18

bool solve(ll n) {
    f(k,2,64,1) {
        ll lo = 2, hi = ceil(pow(INF, 1.0/k));
        while (hi != lo) {
            ll g = (hi + lo)/2;
            ll z = 1;
            f(i,0,k,1) z = g*z + 1;
            if (z > n) hi = g;
            else if (z == n) return true;
            else lo = g + 1; 
        }
    }
    return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) { 
        ll n;
        cin >> n;
        if (solve(n)) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
