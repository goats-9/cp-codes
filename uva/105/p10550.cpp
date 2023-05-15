#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, r, s;
    while (cin >> p >> q >> r >> s) {
        if (!p && !q && !r && !s) break;
        cout << 1080 + 9*((p - q + 40) % 40 + (r - q + 40) % 40 + (r - s + 40) % 40) << "\n";
    }
    return 0;
}