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
	int t, n, w, h;
	cin >> t;
    while (t--) { 
        cin >> n >> w >> h;
        vi a(n), b(n);
        f(i,0,n,1) cin >> a[i];
        f(i,0,n,1) cin >> b[i];
        int l = a[0] - w + h, r = a[0] + w - h, i = 1;
        while (l <= r && i < n) {
            int x1 = a[i] - w + h - b[i], x2 = a[i] + w - h - b[i];
            l = max(l, b[0] + x1);
            r = min(r, b[0] + x2);
            ++i;
        }
        if (l <= r) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
