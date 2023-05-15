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

int binSearch(vi &vec, int i) {
    int l = 0, h = vec.size() - 1, g = (l + h)/2;
    if (vec[0] >= i) return 0;
    if (vec[h] < i) return h + 1;
    while (l != h) {
        if (vec[g] >= i) {
            if (vec[g - 1] < i) return g;
            else h = g;
        } else l = g + 1;
        g = (h+l)/2;
    }
    return g;
} 

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int p, c;
        scanf("%d %d", &p, &c);
        int ans = p, opt = 0;
        vi pr, co;
        if (p != 0) { pr.assign(p, 0); f(i, 0, p, 1) scanf("%d", &pr[i]); sort(pr.begin(), pr.end()); }
        if (c != 0) { co.assign(c, 0); f(i, 0, c, 1) scanf("%d", &co[i]); sort(co.begin(), co.end()); }
        if (p == 0) printf("0 0\n");
        else if (c == 0 && p != 0) printf("%d 0\n", pr[p - 1]);
        else {
            f(i, 0, p, 1) {
                int x = binSearch(co, pr[i]);
                if (ans > x + p - 1 - i) ans = x + p - 1 - i, opt = pr[i];
            }
            f(i, 0, c, 1) {
                int x = binSearch(pr, co[i]);
                if (ans > p - x + i) ans = p - x + i, opt = co[i];
            }
            printf("%d %d\n", opt, ans);
        }
    }
    return 0;
}