#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

void stkRemove(vector<vi> &world, map<int, pair<int, int>> &pos, int key) {
    while(world[pos[key].first].back() != key) {
        int x = world[pos[key].first].back();
        world[x].push_back(x);
        pos[x] = {x, 0};
        world[pos[key].first].pop_back();
    }
}

int main() {
    int n, a, b;
    cin >> n;
    vector<vi> world(n);
    map<int, pair<int, int>> pos;
    f(i, 0, n, 1) {
        world[i].push_back(i);
        pos[i] = {i, 0};
    }
    string cmd, flag;
    while (cin >> cmd) {
        if (cmd == "quit") break;
        cin >> a >> flag >> b;
        if (pos[a].first == pos[b].first) continue;
        if (cmd == "move") {
            if (flag == "onto") {
                stkRemove(world, pos, a);
                stkRemove(world, pos, b);
                world[pos[a].first].pop_back();
                pos[a] = {pos[b].first, pos[b].second + 1};
                world[pos[b].first].push_back(a);         
            } else {
                stkRemove(world, pos, a);
                world[pos[a].first].pop_back();
                int y = world[pos[b].first].size();
                pos[a] = {pos[b].first, y};
                world[pos[b].first].push_back(a);
            }
        } else {
            if (flag == "onto") {
                stkRemove(world, pos, b);
                int n = world[pos[a].first].size(), m = pos[a].second, k = pos[a].first;
                f(i, m, n, 1) {
                    int x = world[k][i];
                    int y = world[pos[b].first].size();
                    pos[x] = {pos[b].first, y};
                    world[pos[b].first].push_back(x);
                }
                f(i, m, n, 1) world[k].pop_back();
            } else {
                int n = world[pos[a].first].size(), m = pos[a].second, k = pos[a].first;
                f(i, m, n, 1) {
                    int x = world[k][i];
                    int y = world[pos[b].first].size();
                    pos[x] = {pos[b].first, y};
                    world[pos[b].first].push_back(x);
                }
                f(i, m, n, 1) world[k].pop_back();
            }
        }
    }
    f(i, 0, n, 1) {
        
        int n = world[i].size();
        if (n == 0) cout << i << ":\n";
        else cout << i << ": ";
        f(j, 0, n, 1) {
            cout << world[i][j];
            if (j != n - 1) cout << " ";
            else cout << "\n";
        }
    }
    return 0;
}