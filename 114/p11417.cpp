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

int gcd(int i, int j) {
    if (i == j) return i;
    else {
        j -= i;
        if (i > j) return gcd(j, i);
        else return gcd(i, j);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        ll g = 0;
        f(i, 1, n, 1) f(j, i + 1, n + 1, 1) g += gcd(i, j);
        printf("%lld\n", g);
    }
    return 0;
}