#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++) {
        x = 1;
        cin >> s;
        int n = s.size(), m = n + 1, e = n + 1;
        for (int j = 0; j < n; j++) {
            if (s[j] != 'M' && s[j] != '?' && s[j] != 'E') {
                cout << "no-theorem\n";
                x = 0;
                break;
            } else if (s[j] == 'M') {
                m = j;
                if (m == 0) {
                    cout << "no-theorem\n";
                    x = 0;
                    break;
                }
            } else if (s[j] == 'E') {
                e = j;
                if (e - m <= 1) {
                    cout << "no-theorem\n";
                    x = 0;
                    break;
                } 
            }
            if (!x) break;
        }
        if (x) {
            if (n == 2*e) cout << "theorem\n";
            else cout << "no-theorem\n";
        }
    }
    return 0;
}