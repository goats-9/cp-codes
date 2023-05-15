#include <bits/stdc++.h>
using namespace std;

vector<int> process(vector<int> &vec) {
    int j = 0, n = vec.size(); 
    vector<int> ret;
    while (j < n) {
        int i = 1;
        ret.push_back(vec[j]);
        while (j + i < n && vec[j] == vec[j + i]) ++i;
        j += i;
    }
    return ret;
}

vector<int> unique(vector<vector<int>> &prob, int &idx) {
    int x;
    vector<int> pno;
    int n = prob[idx].size();
    for (int i = 0; i < n; i++) {
        x = 1;
        for (int j = 0; j < 3; j++) {
            if (j == idx) continue;
            int s = prob[j].size();
            for (int k = 0; k < s; k++) {
                if (prob[idx][i] == prob[j][k]) {
                    x = 0;
                    break;
                }
            }
        }
        if (x) pno.push_back(prob[idx][i]);
    }
    sort(pno.begin(), pno.end());
    return pno;
}

int main() {
    int n, x, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ":\n";
        vector<vector<int>> prob(3, vector<int> ());
        vector<pair<pair<int, int>, vector<int>>> u(3);
        vector<int> ret;
        for (int j = 0; j < 3; j++) {
            cin >> x;
            vector<int> invec;
            for (int k = 0; k < x; k++) {
                cin >> p;
                invec.push_back(p);
            } 
            prob[j] = invec;
        }
        for (int j = 0; j < 3; j++) {
            ret = unique(prob, j);
            ret = process(ret);
            u[j] = {{ret.size(), j + 1}, ret};
        }
        sort(u.begin(), u.end());
        int idx = 2;
        for (int j = 2; j > 0; j--) {
            if (u[j].first.first != u[j - 1].first.first) break;
            else --idx;
        }
        for (int j = idx; j <= 2; j++) {
            cout << u[j].first.second << " " << u[j].first.first;
            if (u[j].first.first > 0) cout << " ";
            for (int k = 0; k < u[j].first.first; k++) {
                cout << (u[j].second)[k];
                if (k != u[j].first.first - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}