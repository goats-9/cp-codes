#include <bits/stdc++.h>
using namespace std;

pair<int, int> run(int &wt_lim, vector<pair<pair<int, int>, int>> &pts) {
    int cur_wt = 0, i = 0;
    int n = pts.size();
    while (i < n) {
        if (pts[i].second) {
            if (cur_wt < wt_lim) cur_wt += pts[i].first.second;
            if (cur_wt == wt_lim) return {i, 0};
            else if (cur_wt > wt_lim) return {i, 1};
        }
        ++i;
    }
    return {n - 1, 0};
}

int main() {
    int t, n, w, dist;
    pair<int, int> max_fill;
    cin >> t;
    for (int i = 0; i < t; i++) {
        dist = 0;
        cin >> w >> n;
        vector<pair<pair<int, int>, int>> pts(n);
        for (int j = 0; j < n; j++) {
            cin >> pts[j].first.first >> pts[j].first.second;
            pts[j].second = 1;
        }
        while (pts[n - 1].second == 1) {
            max_fill = run(w, pts);
            dist += 2*pts[max_fill.first].first.first;
            for (int j = 0; j <= max_fill.first - max_fill.second; j++) pts[j].second = 0;
        }
        cout << dist << "\n";
    }
    return 0;
}