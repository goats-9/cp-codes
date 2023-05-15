#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

ll rev(ll n) {
    ll n_rev = 0;
    while (n != 0) {
        int d = n % 10;
        n /= 10;
        n_rev = 10*n_rev + d;
    }
    return n_rev;
}

int main() {
    int t, x;
    cin >> t;
    ll n;
    f(i, 0, t, 1) {
        scanf("%lld", &n);
        x = 1;
        n += rev(n);
        while (n != rev(n)) {
            n = n + rev(n);
            ++x;
        }
        cout << x << " " << n << "\n";
    }
    return 0;
}