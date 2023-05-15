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
        vvi a(n, vi(n));
        int k = 1, s = n*n + 1;
        if (n%2) { 
            f(i, 0, n - 1, 2) { 
                f(j, 0, n - 1, 2) a[i][j] = k, a[i][j + 1] = s - k, k++;
                a[i][n - 1] = k, a[i + 1][n - 1] = s - k, k++;
                for (int j = n - 2; j >= 0; j -= 2) a[i + 1][j] = k, a[i + 1][j - 1] = s - k, k++;
            }
            f(j, 0, n - 1, 2) a[n - 1][j] = k, a[n - 1][j + 1] = s - k, k++;
            a[n - 1][n - 1] = k;
        } else {
            f(i, 0, n, 2) { 
                f(j, 0, n, 2) a[i][j] = k, a[i][j + 1] = s - k, k++;
                for (int j = n - 1; j >= 0; j -= 2) a[i + 1][j] = k, a[i + 1][j - 1] = s - k, k++;
            }
        }
        f(i, 0, n, 1) {
            f(j, 0, n, 1) cout << a[i][j] << " ";
            cout << nl;
        }
    }
	return 0;
}
