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
        vll a(n), z(n), o(n);
        ll num_ones = 0;
        f(i, 0, n, 1) { cin >> a[i]; num_ones += a[i]; }
        f(i, 1, n, 1) { 
            z[i] = (1 - a[i - 1]) + z[i - 1];
            o[i] = a[i - 1] + o[i - 1];
        }
        ll num_inv = 0;
        f(i, 0, n, 1) if (a[i]) num_inv += n - num_ones - z[i];
        ll delta = 0;
        f(i, 0, n, 1) { 
            if (a[i]) delta = max(delta, o[i] - (n - num_ones - z[i]));
            else delta = max(delta, (n - num_ones - 1 - z[i]) - o[i]);
        }
        cout << num_inv + delta << nl;
	}
	return 0;
}
