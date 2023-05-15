#include <bits/stdc++.h>
using namespace std;

int isTaken(int t1, int t2, int s, int m) {
    if (t2 < s) return 0;
    else {
        if (t1 == 0 && s == 0) return 1;
        else if (m*((t2 - s)/m) + s > t1) return 1;
        else return 0;
    }
}

int main() {
    int t, m, s, c, k, x, y, cur_time;
    cin >> t;
    vector<int> th(4);
    for (int i = 0; i < t; i++) {
        cur_time = 0;
        cin >> m >> s >> th[0] >> th[1] >> th[2] >> th[3] >> c >> k;
        bitset<8> b;
        bitset<4> ans;
        vector<pair<int, int>> time_temp(k);
        for (int j = 0; j < 4; j++) ans[j] = 0;
        for (int j = 0; j < 8; j++) b[j] = c & (1 << j); 
        for (int j = 0; j < k; j++) cin >> time_temp[j].first >> time_temp[j].second;
        for (int j = 0; j < k; j++) {
            if (isTaken(cur_time, cur_time + time_temp[j].first, s, m)) {
                for (int l = 0; l < 4; l++) {
                    if (b[l]) {
                        if (b[l + 4] && th[l] < time_temp[j].second) ans[l] = 1;  
                        else if (!b[l + 4] && th[l] > time_temp[j].second) ans[l] = 1;
                    }
                }
            }
            cur_time += time_temp[j].first;
        }
        cout << "Case " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            if (ans[j]) cout << "yes";
            else cout << "no";
            if (j < 3) cout << " ";
            else cout << "\n";
        }
    }
    return 0;
}