#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        vector<int> a(t);
        for (int i = 0; i < t; i++) cin >> a[i];
        int here = a[0] - a[1], ans = a[0] - a[1];
        for (int i = 1; i < t - 1; i++) {
            here = max(a[i] - a[i + 1], here + a[i] - a[i + 1]);
            ans = max(ans, here); 
        }
        cout << ans << "\n";
    }
    return 0;
}