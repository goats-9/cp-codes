#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, f, x, y, z, s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> f;
        s = 0;
        for (int j = 0; j < f; j++) {
            cin >> x >> y >> z;
            s += x*z;
        }
        cout << s << "\n";
    }
    return 0;
}