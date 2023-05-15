#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        vector<char> p;
        if (s == "#") break;
        int n = s.size(), a = -1, b = -1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[j] > s[i]) {
                    a = i, b = j;
                    for (int k = i; k < n; k++) if (k != j) p.push_back(s[k]);
                    sort(p.begin(), p.end()); 
                    break;
                }
            }
            if (a != -1 && b != -1) break;
        }
        if (a == -1 && b == -1) cout << "No Successor\n";
        else {
            for (int i = 0; i < a; i++) cout << s[i];
            cout << s[b];
            for (char x : p) cout << x;
            cout << "\n";
        }
    }
    return 0;
}