#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, ans, c;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        ans = 0;
        c = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'O') {
                ++c;
                ans += c;
            }
            else c = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}