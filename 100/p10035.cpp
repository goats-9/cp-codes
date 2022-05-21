#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
    int ctr, c;
    string a, b;
    while (cin >> a >> b) {
        if (a == "0" && b == "0") break;
        ctr = 0, c = 0;
        int sa = a.size(), sb = b.size();
        for (int i = 0; i < max(sa, sb); i++) {
            if ((sa - 1 - i < 0 ? 0 : a[sa - 1 - i] - '0') + (sb - 1 - i < 0 ? 0 : b[sb - 1 - i] - '0') + c > 9) {
                ++ctr;
                c = 1;
            } else c = 0;
        }
        if (ctr == 0) cout << "No carry operation.";
        else if (ctr == 1) cout << "1 carry operation.";
        else cout << ctr << " carry operations.";
        cout << "\n";
    }
    return 0;
}