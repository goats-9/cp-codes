#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        if (n > m) cout << ">\n";
        else if (n < m) cout << "<\n";
        else cout << "=\n";
    }
}