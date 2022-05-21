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
    int m, n, ans;
    while (cin >> m >> n) {
        if (!m) break;
        ans = 0;
        vector<string> field(m);
        f(i, 0, m, 1) cin >> field[i];
        f(i, 0, m, 1) {
            f(j, 0, n, 1) {
                queue<pii> bfs;
                if (field[i][j] == '@') {
                    bfs.push({i, j});
                    while (!bfs.empty()) {
                        int a = bfs.front().first, b = bfs.front().second;
                        if (a != 0 && field[a - 1][b] == '@') {
                            field[a - 1][b] = '*';
                            bfs.push({a - 1, b});
                        }
                        if (a != m - 1 && field[a + 1][b] == '@') {
                            field[a + 1][b] = '*';
                            bfs.push({a + 1, b});
                        }
                        if (b != 0 && field[a][b - 1] == '@') {
                            field[a][b - 1] = '*';
                            bfs.push({a, b - 1});
                        }
                        if (b != n - 1 && field[a][b + 1] == '@') {
                            field[a][b + 1] = '*';
                            bfs.push({a, b + 1});
                        }
                        if (a != 0 && b != 0 && field[a - 1][b - 1] == '@') {
                            field[a - 1][b - 1] = '*';
                            bfs.push({a - 1, b - 1});
                        }
                        if (a != 0 && b != n - 1 && field[a - 1][b + 1] == '@') {
                            field[a - 1][b + 1] = '*';
                            bfs.push({a - 1, b + 1});
                        }
                        if (a != m - 1 && b != 0 && field[a + 1][b - 1] == '@') {
                            field[a + 1][b - 1] = '*';
                            bfs.push({a + 1, b - 1});
                        }
                        if (a != m - 1 && b != n - 1 && field[a + 1][b + 1] == '@') {
                            field[a + 1][b + 1] = '*';
                            bfs.push({a + 1, b + 1});
                        }
                        bfs.pop();
                    }
                    ++ans;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}