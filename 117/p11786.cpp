#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, b, ans;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        ans = 0;
        int n = s.size();
        stack<char> stk;
        for (int a = 0; a < n; a++) {
            stk.push(s[a]);
            if (stk.top() == '/') {
                b = 0;
                while (!stk.empty() && stk.top() != '\\') {
                    stk.pop();
                    ++b;
                } 
                if (!stk.empty()) {
                    stk.pop();
                    for (int j = 0; j <= b; j++) stk.push('_');
                    ans += b;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}