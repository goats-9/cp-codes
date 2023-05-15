#include <bits/stdc++.h>
using namespace std;
int main() {
    int b, n, x, y, z, p;
    while (cin >> b >> n) {
        if (b == 0 && n == 0) break;
        p = 1;
        vector<int> res(b);
        for (int i = 0; i < b; i++) cin >> res[i];
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            res[y - 1] += z;
            res[x - 1] -= z;
        }
        for (int i = 0; i < b; i++) {
            if (res[i] < 0) {
                p = 0;
                break;
            }
        }
        if (p) cout << "S\n";
        else cout << "N\n";  
    }
    return 0;
}