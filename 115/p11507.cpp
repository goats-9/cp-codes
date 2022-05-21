#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    string s, ans;
    while (cin >> t) {
        if (t == 0) break;
        ans = "+x";
        for (int i = 0; i < t - 1; i++) {
            cin >> s;
            if (s == "No") continue;
            if (ans[1] != s[1]) {
                if (ans[1] == 'x') {
                    ans[1] = s[1];
                    if (ans[0] == '-') ans[0] = s[0] == '+' ? '-' : '+';
                    else ans[0] = s[0];
                }
            }
            else {
                if (ans[0] == s[0]) ans = "-x";
                else ans = "+x";
            }
        }
        cout << ans << "\n";
    }
    return 0;
}