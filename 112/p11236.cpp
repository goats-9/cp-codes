#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(ll i = a; i < b; i = i + j)
#define N 100.0

int main() {
    f(a, 1, 2001, 1) {
        f(b, a, 2001, 1) {
            f(c, b, 2001, 1) {
                if (a*b*c <= 1000000 || a*b*c >= 2000000000 || a + b + c >= 2000) continue;
                else {
                    int d = (1000000*(a + b + c))/(a*b*c - 1000000);
                    if (a + b + c + d <= 2000 && d >= c && 1000000*(a + b + c + d) == a*b*c*d) printf("%.2f %.2f %.2f %.2f\n", a/N, b/N, c/N, d/N);
                }
            }
        }
    }
    return 0;
}