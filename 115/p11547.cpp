#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << abs((315*n + 36962) / 10) % 10 << "\n";
    }
    return 0;
}