#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c, x;
    while (cin >> n) {
        x = 0;
        for (int i = 0; i < 5; i++) {
            cin >> c;
            if (n == c) ++x; 
        }
        cout << x << "\n";
    }
    return 0;
}