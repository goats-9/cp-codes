#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            int p, q;
            cin >> p >> q;
            if (p == x || q == y) cout << "divisa\n";
            else if (p > x && q > y) cout << "NE\n";
            else if (p > x && q < y) cout << "SE\n";
            else if (p < x && q > y) cout << "NO\n";
            else cout << "SO\n";
        }
    }
    return 0;
}