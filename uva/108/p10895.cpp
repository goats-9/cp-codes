#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    while(cin >> m >> n) {
        vector<vector<int>> a(n, vector<int> (m));
        for (int i = 0; i < m; i++) {
            int p;
            cin >> p;
            vector<int> pos(p), val(p);
            for (int j = 0; j < p; j++) cin >> pos[j];
            for (int j = 0; j < p; j++) cin >> val[j];
            for (int j = 0; j < p; j++) a[pos[j] - 1][i] = val[j];
        }
        cout << n << " "  << m << "\n";
        for (int i = 0; i < n; i++) {
            vector<int> pos, val;
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    pos.push_back(j + 1);
                    val.push_back(a[i][j]);
                }
            }
            int x = pos.size();
            cout << x;
            if (x == 0) cout << "\n";
            else cout << " ";
            for (int j = 0; j < x; j++) {
                cout << pos[j];
                if (j != x - 1) cout << " ";
                else cout << "\n";
            }
            for (int j = 0; j < x; j++) {
                cout << val[j];
                if (j != x - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}