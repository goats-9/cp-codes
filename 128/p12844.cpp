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
    int t;
    scanf("%d", &t);
    f(k, 1, t + 1, 1) {
        vi w(10), a(5);
        f(i, 0, 10, 1) scanf("%d", &w[i]);
        int ans = 0;
        f(i, 0, 10, 1) ans += w[i];
        a[2] = (ans / 4) - w[0] - w[9];
        a[0] = w[1] - a[2];
        a[1] = w[0] - a[0];
        a[4] = w[8] - a[2];
        a[3] = w[9] - a[4]; 
        printf("Case %d: %d %d %d %d %d\n", k, a[0], a[1], a[2], a[3], a[4]);
    }
    return 0;
}