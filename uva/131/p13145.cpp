#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n) {
        cin.ignore(1, '\n');
        if (n == 0) break;
        getline(cin, s);
        for (char x: s) {
            if (x >= 'a' && x <= 'z') cout << char((((((x - 'a') + n) % 26) + 26) % 26) + 'a');
            else if (x >= 'A' && x <= 'Z') cout << char((((((x - 'A') + n) % 26) + 26) % 26) + 'A');
            else cout << x;
        }
        cout << "\n";
    }
    return 0;
}