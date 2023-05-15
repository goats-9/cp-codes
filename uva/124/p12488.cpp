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

int get_idx(vi &a, int val) {
    int n = a.size();
    f(i, 0, n, 1) if (a[i] == val) return i;
    return -1;
}

int main() {
    int t;
    while (scanf("%d", &t) == 1) {
        ll ans = 0;
        int x;
        vi a(t);
        f(i, 0, t, 1) scanf("%d", &a[i]); 
        f(i, 0, t, 1) {
            scanf("%d", &x);
            int y = get_idx(a, x);
            if (y > i) {
                ans += y - i;
                for (int j = y - 1; j >= i; j--) a[j + 1] = a[j];
                a[i] = x;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}