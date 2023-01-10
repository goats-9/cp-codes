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
	int t, m, n;
    cin >> t;
    while (t--) { 
        cin >> n >> m;
        vi a(n), w(n);
        f(i, 0, n, 1) { cin >> a[i]; w[i] = i; }
        vi b(a);
        sort(all(b));
        f(i, 1, n, 1) b[i] = b[i] + b[i - 1];
        int pos = upper_bound(all(b), m) - b.begin() - 1;
        if (pos + 1 < n) { 
            int k = a[pos + 1];
            if (m >= k) {
                vi c;
                f(i, 0, n, 1) {
                    if (i != (pos + 1)) c.pb(a[i]);
                }
                sort(all(c));
                f(i, 1, c.size(), 1) c[i] += c[i - 1];
                int chk = upper_bound(all(c), m - k) - c.begin() - 1;
                if (chk + 1 == pos) ++pos;
            }
        }
        cout << n - pos << nl;
	}
	return 0;
}
