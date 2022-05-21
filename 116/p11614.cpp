#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long f(long long n) {
    long long ans = (long long) sqrt(8*n + 1);
    if (ans % 2 == 0) return ans - 1;
    else return ans;
}

int main() {
    long long n;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << (f(n) - 1)/2 << "\n";
    }
    return 0;
}