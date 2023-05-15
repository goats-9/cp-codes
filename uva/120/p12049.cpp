#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m, in, ans, elem;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ans = 0;
        cin >> n >> m;
        multiset<int> a, b;
        for (int j = 0; j < n; j++) {
            cin >> in;
            a.insert(in);
        } 
        for (int j = 0; j < m; j++) {
            cin >> in;
            b.insert(in);
        } 
        while (!a.empty()) {
            elem = *(a.begin());
            ans += abs(int(a.count(elem) - b.count(elem)));
            a.erase(elem);
            b.erase(elem);
        }
        while (!b.empty()) {
            elem = *(b.begin());
            ans += abs(int(a.count(elem) - b.count(elem)));
            a.erase(elem);
            b.erase(elem);
        }
        cout << ans << "\n";
    }
    return 0;
}