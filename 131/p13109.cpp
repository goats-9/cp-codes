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
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)
#define pb push_back

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, w;
        scanf("%d %d", &m, &w);
        vi e(m);
        f(i, 0, m, 1) scanf("%d", &e[i]);
        sort(e.begin(), e.end());
        int ans = 0, cw = 0;
        while (ans < m && cw <= w) {
            cw += e[ans];
            ++ans;
        }
        if (cw > w) --ans;
        printf("%d\n", ans);
    }
    return 0;
}