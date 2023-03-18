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

bool solve(vi &a) {
    f(i,0,10,1) {
        if (a[i]) {
            --a[i];
            if (i <= 3) {
                f(j,0,4-i,1) {
                    if (a[j]) {
                        --a[j];
                        if (a[3-i-j]) return true;
                        ++a[j];
                    }
                }
            }
            if (i <= 13) {
                f(j,0,14-i,1) {
                    if (j < 10 && a[j]) {
                        --a[j];
                        if ((13-i-j >= 0 && 13-i-j < 10) && a[13-i-j]) return true;
                        ++a[j];
                    }
                }
            }
            if (i <= 23) {
                f(j,0,24-i,1) {
                    if (j < 10 && a[j]) {
                        --a[j];
                        if ((23-i-j >= 0 && 23-i-j < 10) && a[23-i-j]) return true;
                        ++a[j];
                    }
                }
            }
            ++a[i];
        }
    }
    return false;
}

int main() {
	int t, n, x;
	cin >> t;
    while (t--) {
        cin >> n;
        vi a(10);
        f(i,0,n,1) {
            cin >> x;
            ++a[x%10];
        }
        if (solve(a)) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
