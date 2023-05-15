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
#define N 100000007

int main() {
    ll t, x;
    while (scanf("%lld", &t) == 1) {
        if (!t) break;
        vll ans;
        f(i, 1, sqrt(t) + 1, 1) {
            if (!(t % i)) {
                x = (t/i) - 6*i;
                if (x > 0 && !(x%7)) ans.push_back(x/7);
            }
        }
        int n = ans.size();
        if (n == 0) printf("No Solution Possible\n");
        else {
            sort(ans.rbegin(), ans.rend());
            f(i, 0, n, 1) printf("Possible Missing Soldiers = %lld\n", (2*(ans[i]%N)*(ans[i]%N))%N);
        }
        printf("\n");
    }
    return 0;
}