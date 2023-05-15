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
    int h, u, d, f;
    while (cin >> h >> u >> d >> f) {
        if (!h) break;
        double cur = 0;
        double delta = f*u/100.0;
        int x = 0;
        while (cur >= 0 && cur <= h) {
            cur += max(u - x*delta, 0.0);
            ++x;
            if (cur > h) break;
            cur -= d;
        }
        if (cur > h) cout << "success on day " << x;
        else cout << "failure on day " << x;
        cout << "\n";
    }
    return 0;
}