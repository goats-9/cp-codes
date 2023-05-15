#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<pair<string, string>> inputs(n);
        for (int i = 0; i < n; i++) cin >> inputs[i].first >> inputs[i].second;
        vector<pair<string, int>> out(n);
        int pos = -1;
        for (int i = 0; i < n; i++) {
            int k = inputs[i].second.size();
            for (int j = 0; j < k; j++) {
                ++pos;
                pos = pos % n;    
                while(out[pos].second) {
                    ++pos;
                    pos = pos % n;
                }
            }
            while (out[pos].second) {
                ++pos;
                pos = pos % n;
            }
            out[pos] = {inputs[i].first, 1};
        }
        for (int i = 0; i < n; i++) {
            cout << out[i].first;
            if (i == n - 1) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}