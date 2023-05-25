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
	int n;
    int tc = 0;
	while (cin >> n && n) { 
        vi a(n), ctr(10);
        f(i,0,n,1) {cin >> a[i]; ++ctr[a[i]];}
        vi b(n);
        cout << "Game " << ++tc << ":\n";
        while (1) {
            vi chk(10);
            f(i,0,n,1) {cin >> b[i]; ++chk[b[i]];}
            if (b.front() == 0) break;
            vi c = ctr;
            int s = 0, w = 0;
            f(i,0,n,1) if (a[i] == b[i]) ++s, --c[a[i]], --chk[b[i]];
            f(i,0,10,1) w += min(c[i], chk[i]);
            cout << "    (" << s << "," << w << ")\n";
        }
	}
	return 0;
}
