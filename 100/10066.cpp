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
#define EPS 1e-7

int main() {
    int n1, n2, tc = 0;
    while (cin >> n1 >> n2 && n1) {
        vi a(n1+1), b(n2+1);
        f(i,1,n1+1,1) cin >> a[i];
        f(i,1,n2+1,1) cin >> b[i];
        vvi lcs(n1+1, vi(n2+1));
        f(i,0,n1+1,1) lcs[i][0] = 0;
        f(i,0,n2+1,1) lcs[0][i] = 0;
        f(i,1,n1+1,1) f(j,1,n2+1,1) lcs[i][j] = max(lcs[i][j-1], max(lcs[i-1][j], lcs[i-1][j-1] + (a[i] == b[j])));
        cout << "Twin Towers #" << ++tc << "\nNumber of Tiles : " << lcs[n1][n2] << nl << nl;
    }
}
