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
    int t, n;
    scanf("%d", &t);
    f(j, 1, t + 1, 1) {
        scanf("%d", &n);
        vi a(n);
        f(i, 0, n, 1) scanf("%d", &a[i]);
        printf("Case %d: %d\n", j, a[n/2]);
    }
    return 0;
}