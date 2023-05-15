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
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        vi a(n), b(n);
        f(i,0,n,1) cin >> a[i];
        f(i,0,n,1) cin >> b[i];
        int i = 0, ans = 0, l = 0, r = 0;
        while (i < n) {
            bool fl = false;
            int k = 1;
            while (i + k < n && b[i + k] >= b[i + k - 1]) ++k;
            f(j,i,i+k,1) if (a[j] != b[j]) {fl = true; break;}
            if (fl && k > ans) ans = k, l = i + 1, r = i + k;
            i += k;
        }
        cout << l << ' ' << r << nl;
	}
	return 0;
}
