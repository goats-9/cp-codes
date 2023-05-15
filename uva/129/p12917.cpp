#include <bits/stdc++.h>
using namespace std;
int main() {
    int p, h, o;
    while (cin >> p >> h >> o) {
        if (o - p < h) cout << "Hunters win!\n";
        else cout << "Props win!\n";
    }
    return 0;
}