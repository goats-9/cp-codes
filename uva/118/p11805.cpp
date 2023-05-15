#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, p, ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k >> p;
        ans = (k + p) % n;
        if (ans == 0) ans = n;
        cout << "Case " << i + 1 << ": " << ans << "\n";
    }
    return 0;
}