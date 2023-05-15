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
#define sz 1 << 21

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        unordered_set<bitset<sz>> shape;
        f(i, 0, n, 1) {
            bitset<sz> sh;
            vi tree(sz, -1);
            int p, in;
            f(j, 0, k, 1) {
                p = 1;
                scanf("%d", &in);
                while (tree[p] != -1) {
                    if (in > tree[p]) p = p << 1;
                    else p = (p << 1) + 1;
                }
                tree[p] = in;
                sh.set(p);
            }
            shape.insert(sh);
        }
        printf("%d\n", int(shape.size()));
    }
    return 0;
}