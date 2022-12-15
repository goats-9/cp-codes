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
	int t, n;
    scanf("%d", &t);
    while (t--) { 
        cin >> n;
        V<pll> a(n);
        f(i, 0, n, 1) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(all(a));
        cout << n << nl << a[0].second << " " << 0 << nl;
        f(i, 1, n, 1) {
            ll x = a[i - 1].first*(ceil(a[i].first*1.0/a[i - 1].first));
            cout << a[i].second << " " << x - a[i].first << nl;
            a[i].first = x;
        }
	}
	return 0;
}
