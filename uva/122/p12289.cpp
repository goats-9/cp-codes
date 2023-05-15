#include <bits/stdc++.h>
using namespace std;

int numDiff(string s_w, string s_c) {
    int n = s_c.size();
    int c = 0;
    for (int i = 0; i < n; i++) if (s_w[i] != s_c[i]) ++c;
    return c;
}

int main() {
    int t, a, b, c, n;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        n = s.size();
        if (n == 3) {
            if(numDiff(s, "one") <= 1) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
        else cout << 3 << "\n";
    }
    return 0;
}