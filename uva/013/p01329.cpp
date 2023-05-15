#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef map<int, int> mii;

int upd(int x, vi &p, vi& d) {
    if (p[x] == x) return x;
    int a = upd(p[x], p, d);
    d[x] += d[p[x]];
    return p[x] = a;
}

int main() {
    int t, n;
    char c;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vi p(n + 1), d(n + 1);
        for (int j = 0; j <= n; j++) p[j] = j, d[j] = 0;
        while (cin >> c) {
            if (c == 'O') break;
            else if (c == 'E') {
                int x;
                cin >> x;
                upd(x, p, d);
                cout << d[x] << "\n";
            } else if (c == 'I') {
                int x, y;
                cin >> x >> y;
                p[x] = y;
                d[x] = abs(x - y) % 1000;
            }
        }
    }
    return 0;
}