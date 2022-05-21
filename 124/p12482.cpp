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
    int n, l, c;
    while (scanf("%d %d %d", &n, &l, &c) == 3) {
        string s;
        int p_ctr = 0, l_ctr = 0, cl = 0;
        f(i, 0, n, 1) {
            cin >> s;
            int sz = s.size();
            if (cl + sz > c) {
                ++l_ctr;
                if (l_ctr == l) {
                    ++p_ctr;
                    l_ctr = 0;
                }
                cl = sz;
            } else cl += sz;
            if (i != n - 1) {
                if (cl == c) {
                    ++l_ctr;
                    if (l_ctr == l) {
                        ++p_ctr;
                        l_ctr = 0;
                    }
                    cl = 0;
                } else ++cl;
            }
        }
        printf("%d\n", p_ctr + 1);
    }
    return 0;
}