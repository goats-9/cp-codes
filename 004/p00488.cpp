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
    int t, a, n;
    cin >> t;
    f(i, 0, t, 1) {
        cin >> a >> n;
        f(j, 0, n, 1) {
            f(k, 1, a + 1, 1) {
                f(l, 0, k, 1) cout << k;
                cout << "\n";
            }
            f(k, 1, a, 1) {
                f(l, 0, a - k, 1) cout << a - k;
                cout << "\n";
            }
            if (!(i == t - 1 && j == n - 1)) cout << "\n";
        }
    }
    return 0;
}