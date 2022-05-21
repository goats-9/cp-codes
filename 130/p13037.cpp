#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, r, s, x, cl, cr, cs;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> l >> r >> s;
        cout << "Case #" << i + 1 << ":\n";
        vector<pair<int, int>> ans(3);
        set<int> L, S, R;
        for (int j = 0; j < l; j++) {
            cin >> x;
            L.insert(x);
        }
        for (int j = 0; j < r; j++) {
            cin >> x;
            R.insert(x);

        }
        for (int j = 0; j < s; j++) {
            cin >> x;
            S.insert(x);
        }
        set<int> P;
        P.insert(L.begin(), L.end());
        P.insert(R.begin(), R.end());
        P.insert(S.begin(), S.end());
        for (int z: P) {
            (L.find(z) != L.end()) ? cl = 1 : cl = 0;
            (R.find(z) != R.end()) ? cr = 1 : cr = 0;
            (S.find(z) != S.end()) ? cs = 1 : cs = 0;
            if (cl && !cr && !cs) ++ans[0].first;
            else if (!cl && cr && !cs) ++ans[1].first;
            else if (!cl && !cr && cs) ++ans[2].first;
            else if (!cl && cr && cs) ++ans[0].second;
            else if (cl && !cr && cs) ++ans[1].second;
            else if (cl && cr && !cs) ++ans[2].second;
        }
        cout << ans[0].first << " " << ans[0].second<< "\n";
        cout << ans[1].first << " " << ans[1].second << "\n";
        cout << ans[2].first << " " << ans[2].second << "\n";
    }
    return 0;
}