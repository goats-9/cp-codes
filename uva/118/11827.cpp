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
    cin.ignore();
    f(tc,0,t,1) {
        string inp;
        getline(cin, inp);
        stringstream ss(inp);
        int x;
        vi a;
        while (ss >> x) a.pb(x);
        int n = a.size();
        int ans = 0;
        f(i,0,n,1) f(j,i+1,n,1) ans = max(ans, __gcd(a[i], a[j]));
        cout << ans << nl;
    }
	return 0;
}
