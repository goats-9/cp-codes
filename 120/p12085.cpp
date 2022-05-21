#include <bits/stdc++.h>
using namespace std;

string successor(string &x) {
    int n = x.size(), s = x[n - 1] - '0' + 1, c = s / 10;
    string y = x;
    y[n - 1] = char(s % 10 + '0');
    for (int i = n - 2; i >= 0; i--) {
        if (!c) break;
        s = x[i] + 1 - '0';
        c = s / 10;
        y[i] = char(s % 10 +'0');
    }
    if (c) y = '1' + y;
    return y;
}

int consec(vector<string> &n, int &idx) {
    int a = n.size();
    int ctr = 0;
    for (int i = idx; i < a - 1; i++) {
        if (successor(n[i]) == n[i + 1]) ++ctr;
        else break;
    }
    return ctr;
}

int idx_diff(string &a, string &b) {
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return i;
    }
    return n;
}

int main() {
    int t, p, q, ctr = 1;
    while (cin >> t) {
        if (!t) break;
        cout << "Case " << ctr << ":\n";
        vector<string> n(t);
        int i;
        for (i = 0; i < t; i++) cin >> n[i];
        i = 0;
        while (i < t) {
            p = consec(n, i);
            if (p) cout << n[i] << "-" << n[i + p].substr(idx_diff(n[i], n[i + p]), n[i + p].size()) << "\n";
            else cout << n[i] << "\n";
            i += p + 1;
        }
        cout << "\n";
        ++ctr;
    }
    return 0;
}