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

int num_odd(vi &v) {
    int n = v.size(), ans = 0;
    f(i, 0, n, 1) if (v[i]%2) ++ans;
    return ans;
}

int find_odd(vi &v) {
    int n = v.size();
    f(i, 0, n, 1) if (v[i]%2) return i + 1;
    return -1;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        vi col(n), row(n);
        int rs, in;
        f(i, 0, n, 1) {
            rs = 0;
            f(j, 0, n, 1) {
                scanf("%d", &in);
                col[j] += in;
                rs += in;
            
            }
            row[i] = rs;
        }
        int c = num_odd(col), r = num_odd(row);
        if (c == 0 && r == 0) printf("OK\n");
        else if (c == 1 && r == 1) printf("Change bit (%d,%d)\n", find_odd(row), find_odd(col));
        else printf("Corrupt\n");
    }
    return 0;
}