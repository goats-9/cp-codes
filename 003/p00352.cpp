#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    int n, ctr = 0;
    while (scanf("%d", &n) == 1) {
        ++ctr;
        vector<string> a(n);
        f(i, 0, n, 1) cin >> a[i];
        int ans = 0;
        queue<pii> bfs;
        pii in;
        f(i, 0, n, 1) {
            f(j, 0, n, 1) {
                if (a[i][j] == '1') {
                    a[i][j] = '0'; 
                    ++ans;
                    in = make_pair(i, j);
                    bfs.push(in);
                    while (!bfs.empty()) {
                        in = bfs.front();
                        bfs.pop();
                        int x = in.first, y = in.second;
                        if (y > 0 && a[x][y - 1] == '1') {
                            in = make_pair(x, y - 1);
                            bfs.push(in);
                            a[x][y - 1] = '0';
                        } 
                        if (x < n - 1 && y > 0 && a[x + 1][y - 1] == '1') {
                            in = make_pair(x + 1, y - 1);
                            bfs.push(in);
                            a[x + 1][y - 1] = '0';
                        } 
                        if (x < n - 1 && a[x + 1][y] == '1') {
                            in = make_pair(x + 1, y);
                            bfs.push(in);
                            a[x + 1][y] = '0';
                        } 
                        if (x < n - 1 && y < n - 1 && a[x + 1][y + 1] == '1') {
                            in = make_pair(x + 1, y + 1);
                            bfs.push(in);
                            a[x + 1][y + 1] = '0';
                        } 
                        if (y < n - 1 && a[x][y + 1] == '1') {
                            in = make_pair(x, y + 1);
                            bfs.push(in);
                            a[x][y + 1] = '0';
                        } 
                        if (x > 0 && y < n - 1 && a[x - 1][y + 1] == '1') {
                            in = make_pair(x - 1, y + 1);
                            bfs.push(in);
                            a[x - 1][y + 1] = '0';
                        } 
                        if (x > 0 && a[x - 1][y] == '1') {
                            in = make_pair(x - 1, y);
                            bfs.push(in);
                            a[x - 1][y] = '0';
                        } 
                        if (x > 0 && y > 0 && a[x - 1][y - 1] == '1') {
                            in = make_pair(x - 1, y - 1);
                            bfs.push(in);
                            a[x - 1][y - 1] = '0';
                        } 
                    }
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ctr, ans);
    }
    return 0;
}