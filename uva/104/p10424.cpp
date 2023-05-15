#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        int a = 0, b = 0;
        for (char x: s1) {
            if (x >= 'a' && x <= 'z') a += x - 'a' + 1;
            else if (x >= 'A' && x <= 'Z') a += x - 'A' + 1;
            while (a >= 10) {
                a = a/10 + a%10;
            }
        }
        for (char x: s2) {
            if (x >= 'a' && x <= 'z') b += x - 'a' + 1;
            else if (x >= 'A' && x <= 'Z') b += x - 'A' + 1;
            while (b >= 10) {
                b = b/10 + b%10;
            }
        }
        double ans = 100*min((double)a/b, (double)b/a);
        printf("%.2f %%\n", ans);
    }
    return 0;
}