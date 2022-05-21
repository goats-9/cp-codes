#include <bits/stdc++.h>
using namespace std;

int getCycleLength(int i) {
    int c = 1;
    while (i != 1) {
        if (i % 2 == 0) i /= 2;
        else i = 3*i + 1;
        c++;
    }
    return c;
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        int a = min(x, y);
        int b = max(x, y);
        int max = 0, chk; 
        for (int i = a; i <= b; i++) {
            chk = getCycleLength(i);
            if (chk > max) max = chk;
        }
        cout << x << " " << y << " " << max << "\n";
    }
    return 0;
}