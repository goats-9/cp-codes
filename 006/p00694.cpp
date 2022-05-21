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
    ll a, l, ctr = 0;
    while (scanf("%lld %lld", &a, &l) == 2) {
        if (a == -1 && l == -1) break;
        int st = 1;
        ll A = a, L = l;
        while (A > 1) {
            if (A % 2 == 0) A /= 2;
            else A = 3*A + 1;
            if (A > L) break;
            ++st;
        } 
        ++ctr;
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %d\n", ctr, a, l, st);
    }
    return 0;
}