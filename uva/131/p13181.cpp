#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        int ans = 0, x = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') {
                if (x == -1) ans = max(ans, i - 1);
                else ans = max(ans, (i - x - 2)/2);
                x = i;
            } else if (i == n - 1) {
                ans = max(ans, n - x - 2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}