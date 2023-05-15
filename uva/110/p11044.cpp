#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << (n/3)*(m/3) << "\n";
    }
    return 0;
}