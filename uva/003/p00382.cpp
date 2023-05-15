#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int ndigits(int n) {
    int ans = 0;
    while (n != 0) {
        n /= 10;
        ++ans;
    }
    return ans;
}

int facSum(int n) {
    int ans = 0;
    f(i, 1, n/2 + 1, 1) if (n % i == 0) ans += i;
    return ans;
}

int main() {
    cout << "PERFECTION OUTPUT\n";
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int x = ndigits(n);
        f(i, 0, 5 - x, 1) cout << " ";
        cout << n << "  ";
        int y = facSum(n);
        if (y < n) cout << "DEFICIENT\n";
        else if (y == n) cout << "PERFECT\n";
        else cout << "ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
    return 0;
}