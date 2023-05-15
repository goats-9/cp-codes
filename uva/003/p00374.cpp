#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

ll bigmod(ll b, ll p, ll m) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        ll x = bigmod(b, p/2, m)%m;
        return (x*x)%m;
    } else {
        ll x = b%m;
        ll y = bigmod(b, p - 1, m)%m;
        return (x*y)%m;
    }
}

int main() {
    ll b, p, m, x;
    while (cin >> b >> p >> m) cout << bigmod(b, p, m) << "\n";
    return 0;
}