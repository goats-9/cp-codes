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

bool isPrime(int x) {
    f(i, 2, int(sqrt(x)) + 1, 1) if (!(x % i)) return false;
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        ll ctr = 0;
        f(i, 2, n/2 + 1, 1) if (isPrime(i) && isPrime(n - i)) ++ctr;
        printf("%lld\n", ctr);
    }
    return 0;
}