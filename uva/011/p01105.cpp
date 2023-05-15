#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define N 2048

int dp[N][N];

int main() {
    int dx, dy, n, q, x, y, m, ctr = 0;
    while (scanf("%d %d %d %d", &dx, &dy, &n, &q) == 4 && dx) {
        memset(dp, 0, sizeof(dp));
        f(i, 0, n, 1) {
            scanf("%d %d", &x, &y);
            ++dp[x + y][x - y + dy];
        }
        f(i, 1, dx + dy + 1, 1) {
            int s = 0;
            f(j, 1, dx + dy + 1, 1) {
                s += dp[i][j];
                dp[i][j] = dp[i - 1][j] + s;
            }
        }
        printf("Case %d:\n", ++ctr);
        f(k, 0, q, 1) {
            scanf("%d", &m);
            int ans = 0, xm = 1, ym = 1, cd, tx, ty;
            f(j, 1, dy + 1, 1) {
                f(i, 1, dx + 1, 1) {
                    ty = i - j + dy, tx = i + j;
                    int lx = max(tx - m, 1), ly = max(ty - m, 1), rx = min(tx + m, dx + dy), ry = min(ty + m, dx + dy);
                    cd = dp[rx][ry] + dp[lx - 1][ly - 1] - dp[rx][ly - 1] - dp[lx - 1][ry];
                    if (cd > ans) ans = cd, xm = i, ym = j;  
                }
            }
            printf("%d (%d,%d)\n", ans, xm, ym);
        }
    }
    return 0;
}