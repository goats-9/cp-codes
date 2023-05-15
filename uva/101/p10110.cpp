#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(ll i = a; i < b; i = i + j)

int main() {
    ll x, ctr;
    while (cin >> x) {
        if (!x) break;
        ll s = sqrt(x);
        if (s*s == x) cout << "yes";
        else cout << "no";
        cout << "\n";
    }
    return 0;
}