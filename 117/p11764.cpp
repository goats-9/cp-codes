#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, x, y;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<int> a(n);
        x = 0;
        y = 0;
        for (int j = 0; j < n; j++) cin >> a[j];
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) y++;
            else if(a[j] < a[j + 1]) x++;
        } 
        cout << "Case " << i << ": " << x << " " << y << "\n";
    }
    return 0;
}