#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    double h, m, ans;
    while (cin >> s) {
        if (s == "0:00") break;
        h = 0, m = 0, n = s.size();
        if (n == 4) {
            h = 30*(s[0] - '0') + (0.5)*(10*(s[2] - '0') + s[3] - '0');
            m = 6*(10*(s[2] - '0') + s[3] - '0');
        }
        else {
            h = 30*(10*(s[0] - '0') + s[1] - '0') + (0.5)*(10*(s[3] - '0') + s[4] - '0');
            m = 6*(10*(s[3] - '0') + s[4] - '0');
        }
        ans = fabs(h - m);
        printf("%.3f\n", min(ans, 360 - ans));
    }
    return 0;
}