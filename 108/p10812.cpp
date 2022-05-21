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
    ll t, x, y;
    cin >> t;
    f(i, 0, t, 1) {
        cin >> x >> y;
        if (((x + y)%2) == 0 && ((x - y)%2) == 0 && x >= y) cout << (x+y)/2 << " " << (x-y)/2 << "\n";
        else cout << "impossible\n";
    }
    return 0;
}