#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

struct Coord {
    int x, y, z;
};

int main() {
    int l, r, c;
    while (cin >> l >> r >> c && l) {
        V<V<string>> maze(l+2, V<string>(r+2, ""));
        bool vis[l+2][r+2][c+2];
        reset(vis, 0);
        Coord start;
        V<Coord> moves;
        Coord move;
        move.x = -1, move.y = 0, move.z = 0; moves.pb(move);
        move.x = 1; moves.pb(move);
        move.x = 0, move.y = -1; moves.pb(move);
        move.y = 1; moves.pb(move);
        move.y = 0, move.z = -1; moves.pb(move);
        move.z = 1; moves.pb(move);
        f(j,0,r+2,1) maze[0][j] = string(c+2, '#'), maze[l+1][j] = string(c+2, '#');
        f(i,1,l+1,1) {
            maze[i][0] = string(c+2, '#');
            maze[i][r+1] = string(c+2, '#');
            f(j,1,r+1,1) {
                cin >> maze[i][j];
                maze[i][j] = '#' + maze[i][j] + '#';
                f(k,1,c+1,1) if (maze[i][j][k] == 'S') start.x = i, start.y = j, start.z = k;
            }
        }
        queue<Coord> q;
        q.push(start);
        vis[start.x][start.y][start.z] = true;
        int ans = -1;
        bool ok = false;
        while (!q.empty()) {
            int sz = q.size();
            f(i,0,sz,1) {
                Coord r = q.front(); q.pop();
                if (maze[r.x][r.y][r.z] == 'E') {ok = true; break;}
                for (auto del : moves) {
                    Coord nxt;
                    nxt.x = r.x + del.x;
                    nxt.y = r.y + del.y;
                    nxt.z = r.z + del.z;
                    if (!vis[nxt.x][nxt.y][nxt.z] && maze[nxt.x][nxt.y][nxt.z] != '#') {
                        vis[nxt.x][nxt.y][nxt.z] = true;
                        q.push(nxt);
                    }
                }
            }
            ++ans;
            if (ok) break;
        }
        if (ok) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }
	return 0;
}
