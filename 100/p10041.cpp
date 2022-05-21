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
    int t, n, s, x, ans;
    cin >> t;
    f(i, 0, t, 1) {
        ans = 0;
        cin >> n;
        vi r(n);
        f(j, 0, n, 1) cin >> r[j];
        sort(r.begin(), r.end());
        s = r[n / 2];
        f(j, 0, n, 1) ans += abs(s - r[j]); 
        cout << ans << "\n";
    }
    return 0;
}