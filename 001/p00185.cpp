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

int main() {
    string s, p, q, r, o1, o2;
    int a, b, n, j, k, l, sj, sk, sl;
    while (cin >> s) {
        if (s == "#") break;
        n = s.size();
        a = 0;
        b = 0;
        for (char x: s) {
            if (x == '+') {
                p = s.substr(b, a);
                b = a + 1;
            }
            if (x == '=') {
                q = s.substr(b, a);
                break;
            }
            ++a;
        }
        r = s.substr(a + 1, n);
        j = toNum(p), k = toNum(q), l = toNum(r);
        if (j + k == l) o1 = "Correct ";
        else o1 = "Incorrect ";
        sj = j.size(), sk = k.size(), sl = l.size();
        if (sl < max(sj, sk) || sl > max(sj, sk) + 1) o2 = "impossible\n";
        else {
            if (sl == max(sj, sk)) {
                
            }
        }
    }
    return 0;
}