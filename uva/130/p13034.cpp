#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, p;
    cin >> t;
    string s;
    for (int i = 1; i <= t; i++) {
        s = "Yes\n";
        for (int j = 0; j < 13; j++) {
            cin >> p;
            if (p == 0) s = "No\n";
        }
        cout << "Set #" << i << ": " << s;
    }
    return 0;
}