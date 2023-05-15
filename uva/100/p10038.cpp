#include <bits/stdc++.h>
using namespace std;

int chk(vector<int> &b, int &n) {
    for (int i = 1; i < n; i++) if (!b[i]) return 0;
    return 1; 
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n - 1; i++) b[i] = 0;
        for (int i = 0; i < n - 1; i++) ++b[abs(a[i] - a[i + 1])];
        if (chk(b, n)) cout << "Jolly\n";
        else cout << "Not jolly\n";
        if (cin.eof()) break;
    }
    return 0;
}