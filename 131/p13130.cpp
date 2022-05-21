#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    for (int i = 1; i <= t; i++) {
        s = "Y\n";
        vector<int> a(5);
        for (int j = 0; j < 5; j++) {
            cin >> a[j];
        }
        for (int j = 0; j < 4; j++) {
            if (a[j + 1] != a[j] + 1) s = "N\n";
        }
        cout << s;
    }
    return 0;
}