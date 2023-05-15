#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, x, m, j;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ": ";
        m = 0;
        j = 0;
        cin >> x;
        for (int k = 0; k < x; k++) {
            cin >> n;
            m += 10*((n / 30) + 1);
            j += 15*((n / 60) + 1);
        }
        if (m > j) cout << "Juice " << j << "\n";
        else if (m < j) cout << "Mile " << m << "\n";
        else cout << "Mile Juice " << m << "\n"; 
    }
    return 0;
}