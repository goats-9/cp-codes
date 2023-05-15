#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, c, t;
    while (cin >> a) {
        if (a == 0) break;
        cin >> c;
        t = 0;
        vector<int> h(c);
        for (int i = 0; i < c; i++) cin >> h[i];
        t = a - h[0];
        for (int i = 1; i < c; i++) t += max(0, h[i - 1] - h[i]);
        cout << t << "\n";
    }  
    return 0;
}