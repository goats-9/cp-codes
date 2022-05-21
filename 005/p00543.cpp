#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return 0;
    return 1;
}

int ans(int n) {
    for (int i = 3; i < n - 2; i++) if (isPrime(i) && isPrime(n - i)) return i;
    return -1;
}

int main() {
    int n;
    while (cin >> n) {
        if (!n) break;
        int x = ans(n);
        if (x != -1) cout << n << " = " << x << " + " << n - x << "\n";
        else cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}