#include <bits/stdc++.h>
using namespace std;

int getInt(string s, int st_idx, int end_idx) {
    int ans = 0;
    for (int i = st_idx; i < end_idx; i++) ans = 10*ans + (s[i]  - '0');
    return ans;
}

int chk(int d, int m, int y) {
    if (m == 4 || m == 6 || m == 9 || m == 11) return (d <= 30) ? 1 : 0;
    else if (m == 2) {
        if (y % 4 == 0 && y % 400 != 0) return (d <= 29) ? 1 : 0;
        else return (d <= 28) ? 1 : 0;
    }
    else return (d <= 31) ? 1 : 0;
}

int main() {
    FILE *file = fopen("out.txt", "w");
    int n, d, m, y;
    string x, zod;
    cin >> n;
    vector<int> a = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<pair<pair<int, int>, string>> z = {{{1, 21}, "aquarius"}, {{2, 20}, "pisces"}, {{3, 21}, "aries"}, {{4, 21}, "taurus"}, {{5, 22}, "gemini"},
                                    {{6, 22}, "cancer"}, {{7, 23}, "leo"}, {{8, 22}, "virgo"}, {{9, 24}, "libra"},
                                            {{10, 24}, "scorpio"}, {{11, 23}, "sagittarius"}, {{12, 23}, "capricorn"}};
    for (int i = 0; i < n; i++) {
        cin >> x;
        d = getInt(x, 2, 4);
        m = getInt(x, 0, 2);
        y = getInt(x, 4, 8);
        zod = "";
        d += 280;
        while (chk(d, m, y) != 1) {
            d -= a[m - 1];
            if (m == 2) {
                if (y % 4 == 0) {
                    if (y % 100 == 0) {
                        if (y % 400 == 0) --d;
                    }
                    else --d;
                }
            }
            ++m;
            if (m == 13) {
                m = 1;
                ++y;
            }
        }
        fprintf(file, "%d ", i + 1);
        cout << i + 1 << " ";
        if (m < 10) {
            fprintf(file, "0%d/", m);
            cout << 0 << m << "/";
        }
        else  {
            fprintf(file, "%d/", m);
            cout << m << "/";
        }
        if (d < 10) {
            fprintf(file, "0%d/", d);
            cout << 0 << d << "/";
        }
        else {
            cout << d << "/";
            fprintf(file, "%d/", d);
        }
        fprintf(file, "%d ", y);
        cout << y << " ";
        pair<int, int> p = {m, d};
        for (int j = 0; j < 12; j++) {
            if (p < z[j].first) {
                zod = z[(j - 1 + 12) % 12].second;
                break;
            }
        }
        if (zod == "") zod = "capricorn";
        cout << zod << "\n";
        fprintf(file, "%s\n", zod);
    }
    fclose(file);
    return 0;
}