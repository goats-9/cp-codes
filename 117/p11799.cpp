#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) cin >> a[j];
        sort(a.begin(), a.end());
        cout << "Case " << i << ": " << a[n - 1] << "\n";
    }
    return 0;
}