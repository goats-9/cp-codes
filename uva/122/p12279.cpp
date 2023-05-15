#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y, c = 1, t;
    while(cin >> n) {
        x = 0;
        y = 0;
        if (n == 0) break;
        for (int i = 0 ; i < n; i++) {
            cin >> t;
            if (t == 0) ++y;
            else ++x; 
        }
        cout << "Case " << c << ": " << x - y << "\n";
        ++c;
    }
    return 0;
}