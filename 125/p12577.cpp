#include <bits/stdc++.h>
using namespace std;

int main() {
    int c = 1;
    string s;
    while (cin >> s) {
        if (s == "*") break;
        cout << "Case " << c << ": ";
        if (s == "Hajj") cout << "Hajj-e-Akbar\n";
        else cout << "Hajj-e-Asghar\n";
        ++c; 
    }
    return 0;
}