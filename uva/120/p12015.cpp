#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, p;
    cin >> t;
    for (int i = 0; i < t; i++) {
        p = 0;
        cout << "Case #" << i + 1 << ":\n";
        vector<pair<pair<int, int>, string>> inputs(10);
        for (int j = 0; j < 10; j++) {
            cin >> inputs[j].second >> inputs[j].first.first;
            inputs[j].first.second = j;
        }
        sort(inputs.begin(), inputs.end());
        for (int j = 9; j >= 0; j--) {
            if (inputs[j].first.first != inputs[9].first.first) {
                p = j;
                break;
            } 
        }
        for (int j = p + 1; j < 10; j++) {
            cout << inputs[j].second << "\n";
        }
    }
    return 0;
}