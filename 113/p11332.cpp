#include <bits/stdc++.h>
using namespace std;

int g(int n) {
    if (n < 10) return n;
    int s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return g(s);
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << g(n) << "\n";
    }
    return 0;
}