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
    int n, q, x1, x2, y1, y2;
    cin >> n >> q;
    vvll a(n+1, vll(n+1));
    char ch;
    f(i,1,n+1,1) f(j,1,n+1,1) {
        cin >> ch;
        if (ch == '*') a[i][j] = 1;
    }
    f(i,1,n+1,1) f(j,1,n+1,1) a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
    f(i,0,q,1) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << a[y2][x2] + a[y1-1][x1-1] - a[y2][x1-1] - a[y1-1][x2] << nl;
    }
	return 0;
}
