#include <bits/stdc++.h>
using namespace std;

string seqDigits(string &s, string &t) {
    for (char y: s) {
        if (y >= '0' && y <= '9') t += y;
    }
    return t;
}

int isEqual(vector<int> &a_vec, vector<int> &r_vec) {
    int n = a_vec.size();
    for (int i = 0; i < n; i++) {
        if (a_vec[i] != r_vec[i]) return 0;
    }
    return 1;
}

int main() {
    string n_str, m_str;
    int n, m, ctr = 1, r;
    while (getline(cin, n_str, '\n')) {
        r = 1, n = 0, m = 0;
        for (int j = 0; n_str[j] >= '0' && n_str[j] <= '9'; j++) n = 10*n + (n_str[j] - '0');
        if (n == 0) break;
        cout << "Run #" << ctr << ": ";
        vector<string> ans(n);
        for (int i = 0; i < n; i++) getline(cin, ans[i], '\n');
        getline(cin, m_str, '\n');
        for (int j = 0; m_str[j] >= '0' && m_str[j] <= '9'; j++) m = 10*m + (m_str[j] - '0');
        vector<string> resp(m);
        for (int i = 0; i < m; i++) getline(cin, resp[i], '\n');
        string a_str = "", r_str = "", a_cmp, r_cmp; 
        for (int i = 0; i < n; i++) a_str = seqDigits(ans[i], a_str);
        for (int i = 0; i < m; i++) r_str == seqDigits(resp[i], r_str);
        if (a_str == r_str) {
            if (n != m) cout << "Presentation Error\n";
            else {
                for (int i = 0; i < n; i++) {
                    if (ans[i] != resp[i]) {
                        cout << "Presentation Error\n";
                        r = 0;
                        break;
                    }
                }
                if (r == 1) cout << "Accepted\n";
            }
        } else cout << "Wrong Answer\n";
        ctr++;
    }
    return 0;
}