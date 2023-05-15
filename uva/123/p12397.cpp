#include <bits/stdc++.h>
using namespace std;

string toRom(string s) {
    string ans = "";
    int p = s.size() - 1;
    int x = 0;
    char a = 'M', d = 'D', c = 'C', b = 'X', v = 'V', i = 'I', l = 'L', q;
    string m;
    while (p >= 0) {
        m = "";
        if (s[p] < '4') {
            if (x == 0) q = i;  
            else if (x == 1) q = b;
            else if (x == 2) q = c;
            else q = a;
            for (int k = 0; k < s[p] - '0'; k++) m += q;
        }
        else if (s[p] == '4') {
            if (x == 0) m = "IV";
            else if (x == 1) m = "XL";
            else m = "CD";
        }
        else if (s[p] < '9') {
            if (x == 0) {
                q = i;
                m = "V";
            }
            else if (x == 1) {
                m = "L";
                q = b;
            }
            else if (x == 2) {
                m = "D";
                q = c;
            }
            for (int k = 0; k < s[p] - '5'; k++) m += q;  
        }
        else {
            if (x == 0) m = "IX";
            else if (x == 1) m = "XC";
            else if (x == 2) m = "CM";
        }
        --p;
        ++x;
        ans = m + ans;
    }
    return ans;
}

int main() {
    int ans;
    string n, s;
    while (cin >> n) {
        s = toRom(n);
        ans = 0;
        for (char x: s) {
            if (x == 'I') ans += 1;
            else if (x == 'V' || x == 'X' || x == 'L' || x == 'C') ans += 2;
            else if (x == 'D') ans += 3;
            else ans += 4;
        }
        cout << ans << "\n";
    }
    return 0;
}