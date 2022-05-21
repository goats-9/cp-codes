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
    int t, n, p, x, ans;
    cin >> t;
    f(i, 0, t, 1) {
        cin >> n >> p;
        ans = 0;
        vi h(p), d(n);
        f(j, 0, n, 1) {
            if (j % 7 == 5 || j % 7 == 6) d[j] = 0;
            else d[j] = 1;
        }
        f(j, 0, p, 1) cin >> h[j];
        f(j, 0, p, 1) {
            x = 1;
            while (h[j]*x - 1 < n) {
                if (d[h[j]*x - 1] == 1) {
                    d[h[j]*x - 1] = 0;
                    ++ans;
                }
                ++x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}