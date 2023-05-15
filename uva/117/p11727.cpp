#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> a(3);
    for (int i = 0; i < t; i++) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        cout << "Case " << i + 1 << ": " << a[1] <<  "\n";
    }
    return 0;
}