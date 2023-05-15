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
    int t;
    while (scanf("%d", &t) == 1) {
        int i = 1, r = 1;
        while (r % t) { r = (10*r + 1)%t; ++i; }
        printf("%d\n", i);
    }
    return 0;
}