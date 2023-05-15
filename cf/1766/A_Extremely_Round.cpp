#include <bits/stdc++.h>
using namespace std;

int main() { 
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        int ctr = 0;
        while (n >= 10) {
            ++ctr; n/= 10;
        }
        cout << n + 9*ctr << "\n";
    }
}