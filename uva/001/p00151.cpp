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

int j(int n, int k) {
    if (n == 1) return 1;
    else return (j(n - 1, k) + k - 1)%n + 1;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        for (int i = 1; ; ++i) if (j(n - 1, i) == 12) { printf("%d\n", i); break; }
    }
    return 0;
}