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
    int t, n;
    double x, s;
    cin >> t;
    f(i, 0, t, 1) {
        cin >> n;
        vi g(n);
        x = 0.0, s = 0.0;
        f(j, 0, n, 1) {
            cin >> g[j];
            s += g[j];
        }
        s /= n;
        f(j, 0, n, 1) if (g[j] > s) x = x + 1;
        printf("%.3f%%\n", 100*x/n);
    }
    return 0;
}