#include <bits/stdc++.h>
using namespace std;

vector<char> l = {'B', 'U', 'S', 'P', 'F', 'T', 'M'};
vector<int> n = {1, 10, 100, 1000, 10000, 100000, 1000000};

int checkAsc(string &s, map<char, int> &m) {
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (m[s[i]] > m[s[i + 1]]) return 0;
    } 
    return 1;
}

int checkDesc(string &s, map<char, int> &m) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (m[s[i]] < m[s[i + 1]]) return 0;
    } 
    return 1;
}

int checkFreq(string &s) {
    int n = s.size();
    map<char, int> freq_map;
    for (int i = 0; i < 7; i++) freq_map[l[i]] = 0;
    for (int i = 0; i < n; i++) {
        ++freq_map[s[i]];
        if (freq_map[s[i]] > 9) return 0;
    }
    return 1;
}

int toNum(string &s, map<char, int> &m) {
    int n = s.size();
    int ans = 0;
    if (!checkAsc(s, m) && !checkDesc(s, m)) return 0;
    if (!checkFreq(s)) return 0;
    for (char x: s) {
        ans += m[x];
    }
    return ans;
}

int main() {
    map<char, int> m;
    for (int i = 0; i < 7; i++) m[l[i]] = n[i];
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        int ns = toNum(s, m);
        if (!ns) cout << "error\n";
        else cout << ns << "\n";
    }
    return 0;
}