#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, i, k, x, y, z, p, q;
    cin >> t;
    for (int a = 0; a < t; a++) {
        cout << "Case " << a + 1 << ": ";
        cin >> n >> i >> k;
        p = 0, q = 0, y = i, z = 0;
        for (int b = 0; b < n; b++) {
            cin >> x;
            if (x < z) ++q;
            else {
                if (x < y) y = x + i;
                else {
                    ++p;
                    y = x + i + k;
                    z = x + k;
                }
            }
        }
        cout << p << " " << q << "\n";
    }
    return 0;
}