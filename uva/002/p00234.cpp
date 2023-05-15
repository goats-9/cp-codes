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

int getMinErr(vi pr, int x) {
    int n = pr.size();
    pr[0] -= x;
    f(i, 0, n - 1, 1) pr[i + 1] += pr[i];
    f(i, 0, n, 1) pr[i] = abs(pr[i]);
    sort(pr.begin(), pr.end());
    return pr[0];
}

void disp(vi &x) {
    int n = x.size();
    f(i, 0, n, 1) {
        printf("%d", x[i]);
        if (i == n - 1) printf("\n");
        else printf(" ");
    }
}

int main() {
    int p, a, ctr = 0;
    while (scanf("%d", &p) == 1) {
        if (!p) break;
        ++ctr;
        vi pr(p);
        f(i, 0, p, 1) scanf("%d", &pr[i]);
        scanf("%d", &a);
        vector<pii> t(a);
        sort(pr.begin(), pr.end());
        f(i, 0, a, 1) scanf("%d %d", &(t[i].second), &(t[i].first));
        vi ans_err(10, INT_MAX), opt_pr;
        int ans = INT_MAX;
        do {
            vi err(10);
            int sum = 0;
            f(i, 0, a, 1) err[t[i].second] += getMinErr(pr, t[i].first);
            f(i, 0, 10, 1) sum += err[i];
            if (err < ans_err) {
                ans = sum;
                ans_err = err;
                opt_pr = pr;
            }
        } while (next_permutation(pr.begin(), pr.end()));
        printf("Data set %d\nOrder: ", ctr);
        disp(opt_pr);
        printf("Error: %d\n", ans);
    }
    return 0;
}