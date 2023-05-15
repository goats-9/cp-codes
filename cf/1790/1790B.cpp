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
	int t, n, s, r;
	cin >> t;
    while (t--) { 
        cin >> n >> s >> r;
        int q = ceil((double(r))/(n-1));
        vi c(n); c[0] = s - r;
        f(i, 1, n, 1) c[i] = q;
        int d = q*(n-1) - r;
        int i = 1;
        while (d > 0) { 
            int k = min(d,c[i] - 1);
            d -= k, c[i] -= k;
            ++i;
        }
        f(i, 0, n, 1) cout << c[i] << ' ';
        cout << nl;
	}
	return 0;
}
