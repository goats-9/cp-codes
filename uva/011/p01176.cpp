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

int sur(int t) {
    int k = log2(t); 
    return ((t & ((1 << k) - 1)) << 1) | 1;
}

int main() {
    int t;
    while (scanf("%d", &t) == 1) {
        ll p = 0;
        while (sur(t) != t) {
            p += t - sur(t);
            t = sur(t);
        }
        p += 2*t;
        printf("%lld\n", p);
    }
    return 0;
}