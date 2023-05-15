#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y) {
        if (x == -1 && y == -1) break;
        else cout << min((x - y + 100) % 100, (y - x + 100) % 100) << "\n";
    }
    return 0;
}