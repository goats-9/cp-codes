#include <bits/stdc++.h>
using namespace std;

vector<int> getRecord(string &s, int &idx) {
    vector<int> ret;
    int x = 0;
    ret.push_back(10*(s[idx] - '0') + (s[idx + 1] - '0'));
    ret.push_back(10*(s[idx + 3] - '0') + (s[idx + 4] - '0'));
    ret.push_back(10*(s[idx + 6] - '0') + (s[idx + 7] - '0'));
    ret.push_back(10*(s[idx + 9] - '0') + (s[idx + 10] - '0'));
    if (s[idx + 13] == 'n') {
        ret.push_back(0);
        for (int i = 18; s[idx + i] >= '0' && s[idx + i] <= '9'; i++) x = 10*x + (s[idx + i] - '0');
    } else {
        ret.push_back(1);
        for (int i = 17; s[idx + i] >= '0' && s[idx + i] <= '9'; i++) x = 10*x + (s[idx + i] - '0');
    }
    ret.push_back(x);
    return ret;
}

double getCost(vector<vector<int>> &entry, vector<int> &fares) {
    double cost = 0;
    int n = entry.size(), i = 0;
    while (i < n - 1) {
        if (!entry[i][4] && entry[i + 1][4]) {
            cost += double(fares[entry[i][2]])*abs(entry[i + 1][5] - entry[i][5])/100;
            cost += 1;
            i += 2;
        } else ++i;
    }
    return cost + 2;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> fares(24);
        for (int j = 0; j < 24; j++) cin >> fares[j];
        cin.ignore(1, '\n');
        map<string, vector<vector<int>>> plate_record;
        string rec, plate;
        while (getline(cin, rec)) {
            plate = "";
            if (rec == "") break;
            int a = 0;
            while (rec[a] != ' ') {
                plate += rec[a];
                ++a;
            }
            ++a;
            plate_record[plate].push_back(getRecord(rec, a));
        }   
        for (auto x: plate_record) {
            sort(x.second.begin(), x.second.end());
            double ans = getCost(x.second, fares);
            if (ans > 2) {
                cout << x.first << " $";
                printf("%.2f\n", ans);
            }
        }
        if (i != t - 1) cout << "\n";
    }
    return 0;
}