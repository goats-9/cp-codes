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
#define N 500

int n, s;
vi score, target;

void solve(int cur_sc, int max_idx, vi &hit) {
    if (cur_sc == s) {
        int p = hit.size(), q = target.size();
        if (p < q) target = hit;
        else if (p == q && hit > target) target = hit;
    }
    if (hit.size() == target.size()) return;
    f(i, max_idx, n, 1) {
        if (cur_sc + score[i] <= s) {
            hit.push_back(score[i]);
            cur_sc += score[i];
            solve(cur_sc, i, hit);
            cur_sc -= score[i];
            hit.pop_back();
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    f(j, 1, t + 1, 1) {
        scanf("%d %d", &n, &s);
        target.assign(N, 0);
        score.assign(n, 0);
        vi hit;
        f(i, 0, n, 1) scanf("%d", &score[n - 1 - i]);
        printf("Case %d: ", j);
        solve(0, 0, hit);
        int k = target.size();
        if (k == N) printf("impossible\n");
        else {
            printf("[%d] ", k);
            f(i, 0, k, 1) {
                printf("%d", target[i]);
                if (i == k - 1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}