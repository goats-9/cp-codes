#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    ll x, y;
    while (scanf("%lld %lld", &x, &y) == 2) {
        ll ans = 0;
        f(i, 0, 32, 1) {
            ans |= (x & (1 << i)) ^ (y & (1 << i));
        }
        printf("%lld\n", ans);
    }
    return 0;
}