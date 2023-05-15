#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    return (n % 2 == 0) ? n/2 : (n + 1)/2;
}

int main() {
    int n, i, j;
    while (cin >> n >> i >> j) {
        int r = 1;
        while (abs(i - j) != 1 || f(i) != f(j)) {
            i = f(i);
            j = f(j);
            ++r;
        }
        cout << r << "\n";
    }
    return 0;
}