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

double g[100], c[100], dp[100];

int main() {
    f(i, 0, 100, 1) {
        dp[i] = INT_MAX;
        g[i] = 0;
        c[i] = 0;
    }
    double dist, cap, mil, c_init, max_dist;
    int n, ctr = 1;
    while (scanf("%lf", &dist) == 1) { 
        if (dist < 0) break;
        scanf("%lf %lf %lf %d", &cap, &mil, &c_init, &n);
        max_dist = cap*mil;
        g[0] = 0;
        g[n + 1] = dist;
        f(i, 1, n + 1, 1) scanf("%lf %lf", &g[i], &c[i]);
        dp[0] = c_init;
        f(i, 1, n + 2, 1) {
            for (int j = i - 1; j >= 0; j--) {
                if (i != n + 1 && dp[j] != INT_MAX && ((max_dist >= g[i] - g[j] && g[i] - g[j] >= max_dist/2) || (max_dist < g[i + 1] - g[j] && max_dist/2 >= g[i] - g[j]))) dp[i] = min(dp[i], 2.0 + dp[j] + c[i]*(g[i] - g[j])/(100.0*mil));
                if (i == n + 1 && max_dist >= g[i] - g[j]) dp[i] = min(dp[i], dp[j]);
                if (max_dist < g[i] - g[j]) break;
            }
        }
        printf("Data Set #%d\nminimum cost = $%.2f\n", ctr, dp[n + 1]);
        ++ctr;
        f(i, 0, 100, 1) {
            dp[i] = INT_MAX;
            g[i] = 0;
            c[i] = 0;
        }
    }
    return 0;
}