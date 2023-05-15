#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    int n, ans = INT_MIN, s, x;
    cin >> n;
    vector<vi> a(n, vi (n));
    f(i, 0, n, 1) {
        s = 0;
        f(j, 0, n, 1) {
            cin >> x;
            s += x;
            a[i][j] = s;
        }
    }
    f(i, 1, n, 1) f(j, 0, n, 1) a[i][j] += a[i - 1][j];
    f(i, 0, n, 1) {
        f(j, i, n, 1) {
            f(k, 0, n, 1) {
                f(l, k, n, 1) {
                    ans = max(ans, a[j][l] - (i == 0 ? 0 : a[i - 1][l]) - (k == 0 ? 0 : a[j][k - 1]) + ((i == 0 || k == 0) ? 0 : a[i - 1][k - 1]));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}