#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) cin >> a[j];
        sort(a.begin(), a.end());
        cout << 2*(a[n - 1] - a[0]) << "\n";
    }
    return 0;
}