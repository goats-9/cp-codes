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
	int t, n, m, x1, x2, y1, y2;
	cin >> t;
    while (t--) { 
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        int c1 = 0, c2 = 0;
        if (x1 == 1 || x1 == n) {
            if (y1 == 1 || y1 == m) c1 = 2;
            else c1 = 3;
        } else {
            if (y1 == 1 || y1 == m) c1 = 3;
            else c1 = 4;
        }
        if (x2 == 1 || x2 == n) {
            if (y2 == 1 || y2 == m) c2 = 2;
            else c2 = 3;
        } else {
            if (y2 == 1 || y2 == m) c2 = 3;
            else c2 = 4;
        }
        cout << min(c1, min(c2, min(n, m))) << nl;
	}
	return 0;
}
