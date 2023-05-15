#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string mta_from;
    string mta_to;
    string c;
    string admd;
    string prmd;
    string o;
} Entry;

typedef struct {
    string cur_mta;
    string c;
    string admd;
    string prmd;
    string o;
} Message;

int isRep(vector<string> &v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) if (v[i] == v[n - 1]) return 1;
    return 0;
}

void routeMsg(vector<vector<Entry>> &mta, Message &s, vector<string> &circ_mta) {
    circ_mta.push_back(s.cur_mta);
    int n = circ_mta.size();
    if (isRep(circ_mta)) {
        cout << "circular routing detected by " << circ_mta[n - 1] << "\n";
        return;
    }
    n = mta.size();
    for (int i = 0; i < n; i++) {
        if (!(s.cur_mta == mta[i][0].mta_from)) continue;
        for (int j = 0; j < 10; j++) {
            if (!(mta[i][j].c == "*" || s.c == mta[i][j].c)) continue;
            if (!(mta[i][j].admd == "*" || s.admd == mta[i][j].admd)) continue;
            if (!(mta[i][j].prmd == "*" || s.prmd == mta[i][j].prmd)) continue;
            if (!(mta[i][j].o == "*" || s.o == mta[i][j].o)) continue;
            if (s.cur_mta == mta[i][j].mta_to) {
                cout << "delivered to " << s.cur_mta << "\n";
                return;
            } else {
                s.cur_mta = mta[i][j].mta_to;
                routeMsg(mta, s, circ_mta);
                return;
            } 
        }
    }
    cout << "unable to route at " << s.cur_mta << "\n";
    return;
}

int main() {
    int t, n, ctr = 1, l;
    string s1, s2, s3, s4, s5, s6;
    while (cin >> t) {
        vector<vector<Entry>> mta(t, vector<Entry> (10));
        Entry y;
        for (int i = 0; i < t; i++) {
            cin >> s1 >> l;
            for (int j = 0; j < l; j++) {
                cin >> s2 >> s3 >> s4 >> s5 >> s6;
                y = {.mta_from = s1, .mta_to = s2, .c = s3, .admd = s4, .prmd = s5, .o = s6};
                mta[i][j] = y;
            }
        }
        cin >> n;
        cout << "Scenario # " << ctr << "\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " -- ";
            cin >> s1 >> s3 >> s4 >> s5 >> s6;
            Message m = {.cur_mta = s1, .c = s3, .admd = s4, .prmd = s5, .o = s6};
            vector<string> circ_mta;
            routeMsg(mta, m, circ_mta);
        }
        ++ctr;
        cout << "\n";
    }
    return 0;
}