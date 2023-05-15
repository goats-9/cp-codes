#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, c = 0;
    double x, y, z, w;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> z >> w;
        if ((x + y + z <= 125 || x <= 56 && y <= 45 && z <= 25) && w <= 7) {
            cout << 1 << "\n";
            ++c;
        } else cout << 0 << "\n";
    }
    cout << c << "\n";
    return 0;
}