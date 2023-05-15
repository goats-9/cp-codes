#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, n, c = 1;
    string s = "impossible";
    while ((cin >> r >> n) && (r || n)) {
        if (r / n <= 26) cout << "Case " << c << ": " << ceil((float) r / n) - 1 << "\n";
        else cout << "Case " << c << ": " << s << "\n";
        ++c;
    }
    return 0;
}