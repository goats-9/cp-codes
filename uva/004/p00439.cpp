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

int bfs(pii st, pii en) {
    int ans = 0;
    if (st == en) return 0;
    queue<pii> q;
    q.push(st);
    while(!q.empty()) {
        ++ans;
        int n = q.size();
        f(i, 0, n, 1) {
            pii cur = q.front(), mov;
            q.pop();
            int x = cur.first, y = cur.second;
            if (x < 8 && y < 7) {
                mov = make_pair(x + 1, y + 2);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x < 7 && y < 8) {
                mov = make_pair(x + 2, y + 1);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x < 7 && y > 1) {
                mov = make_pair(x + 2, y - 1);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x < 8 && y > 2) {
                mov = make_pair(x + 1, y - 2);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x > 1 && y > 2) {
                mov = make_pair(x - 1, y - 2);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x > 2 && y > 1) {
                mov = make_pair(x - 2, y - 1);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x > 2 && y < 8) {
                mov = make_pair(x - 2, y + 1);
                if (mov == en) return ans;
                q.push(mov);
            }
            if (x > 1 && y < 7) {
                mov = make_pair(x - 1, y + 2);
                if (mov == en) return ans;
                q.push(mov);
            }
        } 
    }
    return -1;
}

int main() {
    string s1, s2;
    pii st, en, cur;
    while (cin >> s1 >> s2) {
        st = {s1[0] - 'a' + 1, s1[1] - '0'}, en = {s2[0] - 'a' + 1, s2[1] - '0'};
        cout << "To get from " << s1 << " to " << s2 << " takes " << bfs(st, en) << " knight moves.\n";
    }
    return 0;
}