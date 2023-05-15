#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        vector<pair<int, int>> inputs(n);
        vector<string> meds(n);
        for (int j = 0; j < n; j++) {
            cin >> meds[j] >> inputs[j].first;
            inputs[j].second = j;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q(inputs.begin(), inputs.end());
        pair<int, int> cur;
        int ctr = 0;
        while (ctr < k) {
            cur = q.top();
            cout << cur.first << " " << meds[cur.second] << "\n";
            cur.first += inputs[cur.second].first;
            q.pop();
            q.push(cur);
            ++ctr;
        }
    }
    return 0;
}