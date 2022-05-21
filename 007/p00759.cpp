#include <bits/stdc++.h>
using namespace std;

int toNum(string s) {
    int ans = 0;
    int p = s.size() - 1;
    while (p >= 0) {
        if (s[p] == 'I') {
            if (ans < 3) {
                ans += 1;
                p--;
            } else return -1;
        }
        else if (s[p] == 'V') {
            if (ans < 4) {
                ans += 5;
                p--;
                if (p < 0) break;
                if (s[p] == 'I' && ans == 5) {
                    if (ans == 5) {
                        ans -= 1;
                        p--; 
                    } else return -1;
                }
            } else return -1;
        }
        else if (s[p] == 'X') {
            if (ans < 30) {
                ans += 10;
                p--;
                if (p < 0) break;
                if (s[p] == 'I' && ans == 10) {
                    if (ans == 10) {
                        ans -= 1;
                        p--;
                    } else return -1;
                }
            } else return -1;
        }
        else if (s[p] == 'L') {
            if (ans < 40) {
                ans += 50;
                p--;
                if (p < 0) break;
                if (s[p] == 'X') {
                    if(ans >= 50 && ans < 60) {
                        ans -= 10;
                        p--;
                    } else return -1;
                }
            } else return -1;
        }
        else if (s[p] == 'C') {
            if (ans < 300) {
                ans += 100;
                p--;
                if (p < 0) break;
                if (s[p] == 'X') {
                    if (ans >= 100 && ans < 110) {
                        ans -= 10;
                        p--;
                    } else return -1;
                }
            } else return -1;
        }
        else if (s[p] == 'D') {
            if (ans < 400) {
                ans += 500;
                p--;
                if (p < 0) break;
                if (s[p] == 'C') {
                    if (ans >= 500 && ans < 600) {
                        ans -= 100;
                        p--;
                    } else return -1;
                }
            } else return -1;
        }
        else if (s[p] == 'M') {
            if (ans < 3000) {
                ans += 1000;
                p--;
                if (p < 0) break;
                if (s[p] == 'C') {
                    if (ans >= 1000 && ans < 1100) {
                        ans -= 100;
                        p--;
                    } else return -1;
                }
            } else return -1;
        }
    }
    return ans;
}

int main() {
    string s;
    while (cin >> s) {
        int x = toNum(s);
        if (x != -1) cout << x << "\n";
        else cout << "This is not a valid number\n";
    }
    return 0;
}