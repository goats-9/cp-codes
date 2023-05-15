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
	int t;
    ll n, c, d;
    scanf("%d", &t);
    while (t--) { 
        cin >> n >> c >> d;
        vll a(n);
        f(i, 0, n, 1) cin >> a[i];
        sort(all(a));
        reverse(all(a));
        f(i, 1, n, 1) a[i] += a[i - 1];
        if (d*a[0] < c) { cout << "Impossible\n"; continue;}
        if (a[min(n, d) - 1] >= c) { cout << "Infinity\n"; continue; }
        ll l = 0, r = d - 1, g = 0;
        while (l != r) { 
            g = (l + r)/2;
            ll quot = d/(g + 1), rem = d%(g + 1);
            ll sm = quot*a[min(g+1,n)-1] + ((rem) ? a[min(rem,n)-1] : 0);
            if (sm >= c) l = g + 1;
            else r = g;
        }
        ll quot = d/(g + 1), rem = d%(g + 1);
        ll sm = quot*a[min(g+1,n)-1] + ((rem) ? a[min(rem,n)-1] : 0);
        if (sm < c) --g;
        cout << g << nl;
	}
	return 0;
}
