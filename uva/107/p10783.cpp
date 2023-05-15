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
    int t;
    cin >> t;
    f(i, 0, t, 1) {
        int s = 0, a, b;
        cin >> a >> b;
        f(j, a, b + 1, 1) if (j % 2) s += j;
        cout << "Case " << i + 1 << ": " << s << "\n";
    }
    return 0;
}