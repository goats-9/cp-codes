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
#define MAXN 1024
#define MAXG 110

int N, G, pr[MAXN], wt[MAXN], memo[MAXN][MAXG];

int dp(int id, int remW) {
    if ((id == N) || (remW == 0)) return 0;
    int &ans = memo[id][remW];
    if (ans != -1) return ans;
    if (wt[id] > remW) return ans = dp(id + 1, remW);
    return ans = max(dp(id + 1, remW), pr[id] + dp(id + 1, remW - wt[id]));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(pr, 0, sizeof(pr));
        memset(wt, 0, sizeof(wt));
        memset(memo, -1, sizeof(memo));        
        scanf("%d", &N);
        f(i, 0, N, 1) scanf("%d %d", &pr[i], &wt[i]);
        scanf("%d", &G);
        int MW, ans = 0;
        while (G--) {
            scanf("%d", &MW);
            ans += dp(0, MW);
        }
        printf("%d\n", ans);
    }
    return 0;
}