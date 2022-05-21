#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Lumberjacks:\n";
    int t, x, p, q;
    cin >> t;
    for (int i = 0; i < t; i++) {
        p = 1;
        q = 1;
        vector<int> h(10);
        for (int j = 0; j < 10; j++) cin >> h[j];
        for (int j = 0; j < 9; j++) {
            if (h[j] > h[j + 1]) {
                p = 0;
                break;
            }
        }
        for (int j = 0; j < 9; j++) {
            if (h[j] < h[j + 1]) {
                q = 0;
                break;
            }
        }
        if (p == 1 || q == 1) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
    return 0;
}