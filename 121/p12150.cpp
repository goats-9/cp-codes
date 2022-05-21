#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, idx;
    while (cin >> n) {
        if (!n) break;
        x = 1;
        vector<pair<int, int>> car_pos(n);
        for (int i = 0; i < n; i++) cin >> car_pos[i].first >> car_pos[i].second;
        vector<pair<int, int>> pos_occ(n);
        for (int i = 0; i < n; i++) {
            idx = i + car_pos[i].second;
            if (idx >= 0 && idx < n && !pos_occ[idx].second) pos_occ[idx] = {car_pos[i].first, 1};
            else {
                x = 0;
                break;
            }
        }
        if (!x) cout << -1 << "\n";
        else {
            for (int i = 0; i < n; i++) {
                cout << pos_occ[i].first; 
                if (i == n - 1) cout << "\n";
                else cout << " ";
            }
        }
    }
    return 0;
}