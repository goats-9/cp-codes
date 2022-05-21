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
    int m = prob.size();
    int n = prob[idx].size();
    for (int i = 0; i < n; i++) {
        x = 1;
        for (int j = 0; j < m; j++) {
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
    return process(pno);
}

int main() {
    int t, n, x, p, s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        s = 0;
        cout << "Case " << i + 1 << ": ";
        cin >> n; 
        vector<vector<int>> prob(n, vector<int> ());
        vector<int> u(n), ret;
        for (int j = 0; j < n; j++) {
            cin >> x;
            for (int k = 0; k < x; k++) {
                cin >> p;
                prob[j].push_back(p);
            } 
        }
        for (int j = 0; j < n; j++) {
            ret = unique(prob, j);
            u[j] = ret.size();
            s += u[j];
        }
        for (int j = 0; j < n; j++) {
            printf("%lf%%", 100*double(u[j])/s);
            if (j == n - 1) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}