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
    int m, n, s, x = 1;
    while (cin >> m >> n) {
        if (!m && !n) break;
        if (x != 1) cout << "\n";
        vector<string> field(m);
        f(i, 0, m, 1) cin >> field[i];
        cout << "Field #" << x << ":\n"; 
        f(i, 0, m, 1) {
            f(j, 0, n, 1) {
                if (field[i][j] == '*') cout << "*";
                else {
                    s = 0;
                    if (j != 0 && field[i][j - 1] == '*') ++s;
                    if (j != n - 1 && field[i][j + 1] == '*') ++s;
                    if (i != 0 && field[i - 1][j] == '*') ++s;
                    if (i != m - 1 && field[i + 1][j] == '*') ++s;
                    if (i != 0 && j != 0 && field[i - 1][j - 1] == '*') ++s;
                    if (i != 0 && j != n - 1 && field[i - 1][j + 1] == '*') ++s;
                    if (i != m - 1 && j != 0 && field[i + 1][j - 1] == '*') ++s;
                    if (i != m - 1 && j != n - 1 && field[i + 1][j + 1] == '*') ++s;
                    cout << s;
                }
            }
            cout << "\n";
        }
        ++x;
    }
    return 0;
}