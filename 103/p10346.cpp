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
    int n, k;
    while (cin >> n >> k) {
        int ans = n;
        while (n >= k) {
            ans += n/k;
            n = n/k + n%k;
        }
        cout << ans << "\n";
    }
    return 0;
}