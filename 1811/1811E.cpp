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

ll countNumbersWith4(ll n) {
   if (n < 4) return 0;
   ll d = log10l(n);
   vll a(d + 1);
   a[0] = 0, a[1] = 1;
   for (int i=2; i<=d; i++) a[i] = a[i-1]*9 + ceil(pow(10,i-1));
   ll p = ceil(pow(10LL, d));
   ll msd = n/p;
   if (msd == 4) return (msd)*a[d] + (n%p) + 1;
   if (msd > 4) return (msd-1)*a[d] + p + countNumbersWith4(n%p);
   return (msd)*a[d] + countNumbersWith4(n%p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
    ll n;
    while (t--) {
        cin >> n;
        ll sm = n, prev = 0LL, y = 0LL;
        while (prev != sm) {
            ll x = countNumbersWith4(sm);
            prev = sm;
            sm += x - y;
            y = x;
        }
        cout << sm << nl;
	}
	return 0;
}
