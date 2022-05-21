#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back

ll memo[8000];
vi type = {1, 5, 10, 25, 50};

int main() {
    memset(memo, 0, sizeof(memo));
    memo[0] = 1;
    f(i, 0, 5, 1) {
        f(j, type[i], 7490, 1) {
            memo[j] += memo[j - type[i]];
        }
    }
    int t;
    while (scanf("%d", &t) == 1) {
        printf("%lld\n", memo[t]);        
    }
    return 0;
}