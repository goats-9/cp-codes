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

bool cmp(pii x, pii y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
}

bool geq(int x, int y) { return x >= y; }

int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        vector<pii> d(m);
        f(i, 0, m, 1) scanf("%d %d", &d[i].first, &d[i].second);
        sort(d.begin(), d.end(), cmp);
        int k = 0;
        vi L(m, -1);
        f(i, 0, m, 1) {
            int pos = lower_bound(L.begin(), L.begin() + k, d[i].second, geq) - L.begin();
            L[pos] = d[i].second;
            if (pos == k) ++k; 
        }
        printf("%d\n", k);
    }
    return 0;
}