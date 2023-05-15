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

void solve(ll x, ll y, ll z) {
    if (!x || !y || !z) { printf("Invalid\n"); return; }
    if (x + y <= z || y + z <= x || z + x <= y) { printf("Invalid\n"); return; }
    if (x == y && y == z) { printf("Equilateral\n"); return; }
    if ((x == y && y != z) || (x != y && z == x) || (x != y && y == z)) { printf("Isosceles\n"); return; }
    printf("Scalene\n");
}

int main() {
    int t;
    scanf("%d", &t);
    f(i, 1, t + 1, 1) {
        ll x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        printf("Case %d: ", i);
        solve(x, y, z);
    }
    return 0;
}