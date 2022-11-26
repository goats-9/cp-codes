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
        vi a(n);
        f(i, 0, n, 1) cin >> a[i];
        sort(all(a));
        int i = 0;
        ll ans = 0;
        while (i < n) { 
            int k = 0;
            while (i + k < n && a[i + k] == a[i]) ++k;
            if (i) ans = max(ans, ll(i)*(n - i));
            else {
                if (i + k == n) ans = max(ans, ll(n)/2);
                else ans = max(ans, k*(ll(n) - k));
            }
            i += k;
        }
        cout << ans << nl;
	}
	return 0;
}