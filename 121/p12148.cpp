#include <bits/stdc++.h>
using namespace std;

vector<int> x = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> x_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(int y) {
    if (y % 4 == 0) {
        if (y % 400 == 0) return 1;
        else if (y % 100 == 0) return 0;
        else return 1;
    } else return 0;
}

int isConsec(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y2 - y1 == 1) {
        if (d1 == 31 && m1 == 12 && d2 == 1 && m2 == 1) return 1;
        else return 0;
    } else if (y1 == y2) {
        if (m2 - m1 == 1) {
            if (isLeap(y1)) {
                if (d1 == x_leap[m1 - 1] && d2 == 1) return 1;
                else return 0;
            } else {
                if (d1 == x[m1 - 1] && d2 == 1) return 1;
                else return 0;
            }
        } else if (m2 == m1) {
            if (d2 - d1 == 1) return 1;
            else return 0;
        } else return 0;
    } else return 0;
}

int main() {
    int t, d_in, d, m_in, m, y_in, y, c_in, c, ans, ctr;
    while (cin >> t) {
        ans = 0, ctr = 0;
        if (t == 0) break;
        cin >> d >> m >> y >> c;
        for (int i = 1; i < t; i++) {
            cin >> d_in >> m_in >> y_in >> c_in;
            if (isConsec(d, m, y, d_in, m_in, y_in)) {
                ans += c_in - c;
                ++ctr;
            }
            d = d_in, m = m_in, y = y_in, c = c_in;
        }
        cout << ctr << " " << ans << "\n";
    }
    return 0;
}