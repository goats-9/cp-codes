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
	f(k,1,t+1,1) { 
        int n;
        cin >> n;
        vll a(n);
        f(i,0,n,1) cin >> a[i];
        ll num = n, denom = 0;
        ll pr = 1;
        f(i,0,n,1) pr *= a[i];
        f(i,0,n,1) denom += pr/a[i];
        num *= pr;
        ll g = __gcd(num, denom);
        cout << "Case " << k << ": " << num/g << '/' << denom/g << nl;
	}
	return 0;
}
