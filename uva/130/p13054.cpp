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
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)
#define pb push_back

int main() {
    int T;
    scanf("%d", &T);
    f(j, 1, T + 1, 1) {
        int n, h, a, d;
        scanf("%d %d %d %d", &n, &h, &a, &d);
        vi hippo(n);
        f(i, 0, n, 1) scanf("%d", &hippo[i]);
        sort(hippo.begin(), hippo.end());
        int t = 0, s = 0, l = n - 1;
        while (s <= l) {
            if (s < l && hippo[s] + hippo[l] < h) t += min(d, 2*a), ++s, --l;
            else t += a, --l;
        }
        printf("Case %d: %d\n", j, t);
    }
    return 0;
}