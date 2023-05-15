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

int fib[60];

int main() {
    fib[0] = 1, fib[1] = 1;
    f(i, 2, 52, 1) fib[i] = fib[i - 1] + fib[i - 2];
    int n;
    while (scanf("%d", &n) == 1) {
        if (!n) break;
        printf("%d\n", fib[n]);
    }
    return 0;
}