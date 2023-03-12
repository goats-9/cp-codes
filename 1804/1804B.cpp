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
	int t, n, k, d, w;
	cin >> t;
    while (t--) { 
        cin >> n >> k >> d >> w;
        vi a(n), b(n);
        f(i, 0, n, 1) cin >> a[i];
        f(i, 0, n, 1) b[i] = a[i] + w;
        int i = 0, ans = 0;
        while (i < n) {
            int j = 0, l = b[i], r = b[i] + d;
            while (i + j < n && j < k && l <= b[i + j] && r >= a[i + j]) j++;
            i += j; ans++;
        }
        cout << ans << nl;
	}
	return 0;
}
