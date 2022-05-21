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
    int ctr = 0, n, d, x, y;
    while (scanf("%d %d", &n, &d) == 2 && n) {
        ++ctr;
        vector<pdd> range;
        int ans = 0, fl = 0;
        f(i, 0, n, 1) {
            scanf("%d %d", &x, &y);
            pdd put;
            if (d < y) fl = -1;
            else {
                double del = sqrt(double(d)*d - y*y);
                put.first = x - del;
                put.second =  x + del;
                range.pb(put);
            }
        }
        sort(range.begin(), range.end());
        printf("Case %d: ", ctr);
        if (fl == -1) printf("-1\n");
        else {
           int i = 0;
           double key = -1e9;
           while (i < n) {
               while (i < n && range[i].first <= key) {
                   key = (range[i].second > key) ? key : range[i].second;
                   ++i;
               }
               ++ans;
               key = range[i].second;
           }
           printf("%d\n", ans - 1);
        }
    }
    return 0;
}   