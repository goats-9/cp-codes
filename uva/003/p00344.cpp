#include <bits/stdc++.h>
using namespace std;

string toRom(int n) {
    string ans = "", m;
    int x = 0, d;
    char c = 'C', b = 'X', v = 'V', i = 'I', l = 'L', q;
    while (n != 0) {
        m = "";
        d = n % 10;
        n /= 10;
        if (d < 4) {
            if (x == 0) q = i;  
            else if (x == 1) q = b;
            else if (x == 2) q = c;
            for (int k = 0; k < d; k++) m += q;
        }
        else if (d == 4) {
            if (x == 0) m = "IV";
            else if (x == 1) m = "XL";
        }
        else if (d < 9) {
            if (x == 0) {
                q = i;
                m = "V";
            }
            else if (x == 1) {
                m = "L";
                q = b;
            }
            for (int k = 0; k < d - 5; k++) m += q;  
        }
        else {
            if (x == 0) m = "IX";
            else if (x == 1) m = "XC";
        }
        ++x;
        ans = m + ans;
    }
    return ans;
}

int main() {
    int t, i, v, x, l, c;
    string s;
    while (cin >> t) {
        if (t == 0) break;
        i = 0, v = 0, x = 0, l = 0, c = 0;
        for (int y = 1; y <= t; y++) {
            s = toRom(y);
            for (char z: s) {
                if (z == 'I') ++i;
                if (z == 'V') ++v;
                if (z == 'X') ++x;
                if (z == 'L') ++l;
                if (z == 'C') ++c;
            }
        }
        cout << t << ": " << i << " i, " << v << " v, " << x << " x, " << l << " l, " << c << " c\n"; 
    }
    return 0;
}