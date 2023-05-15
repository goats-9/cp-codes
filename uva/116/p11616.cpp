#include <bits/stdc++.h>
using namespace std;

int toNum(string s) {
    int ans = 0;
    int p = s.size() - 1;
    while (p >= 0) {
        if (s[p] == 'I') {
            ans += 1;
            p--;
        }
        else if (s[p] == 'V') {
            ans += 5;
            p--;
            if (p < 0) break;
            if (s[p] == 'I') {
                ans -= 1;
                p--; 
            }
        }
        else if (s[p] == 'X') {
            ans += 10;
            p--;
            if (p < 0) break;
            if (s[p] == 'I') {
                ans -= 1;
                p--;
            }
        }
        else if (s[p] == 'L') {
            ans += 50;
            p--;
            if (p < 0) break;
            if (s[p] == 'X') {
                ans -= 10;
                p--;
            }
        }
        else if (s[p] == 'C') {
            ans += 100;
            p--;
            if (p < 0) break;
            if (s[p] == 'X') {
                ans -= 10;
                p--;
            }
        }
        else if (s[p] == 'D') {
            ans += 500;
            p--;
            if (p < 0) break;
            if (s[p] == 'C') {
                ans -= 100;
                p--;
            }
        }
        else if (s[p] == 'M') {
            ans += 1000;
            p--;
            if (p < 0) break;
            if (s[p] == 'C') {
                ans -= 100;
                p--;
            }
        }
    }
    return ans;
}

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
    string s;
    while (cin >> s) {
        if (s[0] >= '0' && s[0] <= '9') cout << toRom(s) << "\n";
        else cout << toNum(s) << "\n";
    }
    return 0;
}