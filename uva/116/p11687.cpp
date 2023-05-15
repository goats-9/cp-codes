#include <bits/stdc++.h>
using namespace std;

int nChars(string s) {
    int c = 0;
    for (char x: s) ++c;
    return c;
}

int nDigits(int n) {
    int c = 0;
    while(n != 0) {
        n /= 10;
        ++c;
    }
    return c;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "END") break;
        else if (s == "1") cout << 1 << "\n";
        else {
            int n = nChars(s);
            int c = 1;
            while (n != 1) {
                n = nDigits(n);
                ++c;
            }
            cout << c + 1 << "\n";
        }
    }
    return 0;
}