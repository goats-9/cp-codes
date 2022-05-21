#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, d, a = 0;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++) {
        cin >> s;
        if (s == "donate") {
            cin >> d;
            a += d;
        }
        else if (s == "report") {
            cout << a << "\n";
        }
    }
    return 0;
}