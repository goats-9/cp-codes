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
    int n, x = 1;
    while (cin >> n) {
        if (!n) break;
        vi w(n);
        f(i, 0, n, 1) cin >> w[i];
        int m = 0;
        f(i, 0, n, 1) m += w[i];
        m /= n;
        int ans = 0;
        f(i, 0, n, 1) if (w[i] - m > 0) ans += w[i] - m; 
        cout << "Set #" << x << "\nThe minimum number of moves is " << ans << ".\n\n";
        ++x;
    }
    return 0;
}