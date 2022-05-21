#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int n = s.size();
        if (s == "1" || s == "4" || s == "78") cout << "+\n";
        else if (s[n - 2] == '3' && s[n - 1] == '5') cout << "-\n";
        else if (s[0] == '9' && s[n - 1] == '4') cout << "*\n";
        else cout << "?\n";
    }
    return 0;
}