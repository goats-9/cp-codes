#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    int t, l, x;
    cin >> t;
    f(i, 0, t, 1) {
        cin >> l;
        vi c(l);
        f(j, 0, l, 1) cin >> c[j];
        x = 0;
        f(j, 0, l - 1, 1) {
            f(k, 0, l - j - 1, 1) {
                if (c[k] > c[k + 1]) {
                    int t = c[k];
                    c[k] = c[k + 1];
                    c[k + 1] = t;
                    ++x;
                }
            }
        } 
        cout << "Optimal train swapping takes " << x << " swaps.\n";
    }
    return 0;
}