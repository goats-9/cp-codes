#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z;
    while (cin >> x >> y >> z) {
        if (x != y && x != z) cout << "A\n";
        else if (x != y && y != z) cout << "B\n";
        else if (z != y && x != z) cout << "C\n";
        else cout <<"*\n";
    }
    return 0;
}