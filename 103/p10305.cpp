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
    map<int, vi> dep;
    int n, m, a, b;
    while (cin >> n >> m) {
        if (!n) break;
        mii root;
        vi topo_sort;
        f(i, 1, n + 1, 1) root[i] = 1;
        f(i, 0, 1, m) {
            cin >> a >> b;
            root[b] = 0;
            dep[a].push_back(b);
        }
        f(i, 1, n + 1, 1) {
            if (root[i]) topo_sort.push_back(i);
            int n = dep[a]
        }
    }
    return 0;
}