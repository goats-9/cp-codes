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

int assess(int j, vector<pii> &s, int a) {
    int p, q, r_p, r_q;
    f(i, 0, a, 1) {
        p = s[i].first, q = s[i].second, r_p = j & (1 << (abs(p) - 1)), r_q = j & (1 << (abs(q) - 1));
        if (r_p) {
            if (r_q && q < 0) return 0;
            if (!r_q && q > 0) return 0;
        }
    }
    return 1;
}

int main() {
    int i, a;
    while (scanf("%d %d", &i, &a) == 2) {
        if (!i && !a) break;
        vector<pii> s(a);
        f(j, 0, a, 1) scanf("%d %d", &s[j].first, &s[j].second);
        // Represent using binary
        for (int j = (1 << i) - 1; j >= 0; j--) {
            if (assess(j, s, a)) {
                int ans = 0;
                f(k, 0, i, 1) ans += (j & (1 << k)) ? 1 : 0;
                cout << ans << "\n";
                break;
            }
        }
    }
    return 0;
}