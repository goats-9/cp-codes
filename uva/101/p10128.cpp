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
    ll DP[20][20][20];
    memset(DP, 0, sizeof(DP));
    DP[1][1][1] = 1;
    f(N, 2, 14, 1)
        f(P, 1, N + 1, 1)
            f(R, 1, N + 1, 1)
                DP[N][P][R] = DP[N-1][P][R]*(N-2) + DP[N-1][P-1][R] + DP[N-1][P][R-1];
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        printf("%lld\n", DP[x][y][z]);
    }
    return 0;
}