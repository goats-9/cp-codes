#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    ll n;
    while (cin >> n) {
        if (n < 0) break;
        ll ans = (n*(n + 1))/2 + 1;
        cout << ans << "\n";
    }
    return 0;
}