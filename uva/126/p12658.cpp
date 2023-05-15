#include <bits/stdc++.h>
using namespace std;

int dig(vector<string> &s, int i) {
    if (s[0][4*i] != s[0][4*i + 1]) return 1;
    else {
        if (s[3][4*i] == '*') return 2;
        else return 3;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> s(5);
    for (int i = 0; i < 5; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cout << dig(s, i);
    cout << "\n";
    return 0;
}