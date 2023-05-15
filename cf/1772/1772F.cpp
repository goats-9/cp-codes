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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int n, m, k;
V<V<string>> a;
V<V<pii>> adj;

struct tr {
    int op, x, y;
};

int main() {
	cin >> n >> m >> k;
    a.assign(k + 1, V<string>(n));
    adj.assign(k + 1, V<pii>());
    V<bool> oc(k + 1, false);
    f(i, 0, k + 1, 1) f(j, 0, n, 1) cin >> a[i][j];
    f(i, 0, k + 1, 1) f(j, i + 1, k + 1, 1) { 
        // Anything between a[i] and a[j]?
        // 0 for copy
        // 1 for copy and manipulate
        if (a[i] == a[j]) adj[i].pb(pii(0, j)), adj[j].pb(pii(0, i));
        else {
            int fl = 1, ctr = 0;
            f(p, 0, n, 1) f(q, 0, m, 1) if (a[i][p][q] != a[j][p][q]) { 
                // i is parent of j
                if ((a[j][p][q] == a[j][p - 1][q]) && (a[j][p][q] == a[j][p + 1][q]) && (a[j][p][q] == a[j][p][q - 1]) && (a[j][p][q] == a[j][p][q + 1])) ++ctr;
            }
            if (!oc[i] && fl == 1 && ctr == 1) { 
                oc[i] = true;
                adj[i].pb(pii(1, j));
                continue;
            }
            fl = 1, ctr = 0;
            f(p, 0, n, 1) f(q, 0, m, 1) if (a[i][p][q] != a[j][p][q]) { 
                // i is child of j
                if ((a[i][p][q] == a[i][p - 1][q]) && (a[i][p][q] == a[i][p + 1][q]) && (a[i][p][q] == a[i][p][q - 1]) && (a[i][p][q] == a[i][p][q + 1])) ++ctr;
            }
            if (!oc[j] && fl == 1 && ctr == 1) { 
                oc[j] = true;
                adj[j].pb(pii(1, i));
                continue;
            }
        }
    }
    vi p(k + 1, -1);
    f(i, 0, k + 1, 1) f(j, 0, adj[i].size(), 1) if (adj[i][j].first == 1) p[j] = i;
    int rt = 0;
    f(i, 0, k + 1, 1) if (p[i] == -1) {rt = i + 1; break;}
    cout << rt << nl;
    --rt;
    f(i, 0, k + 1, 1) sort(all(adj[i]));
    V<tr> moves;
    while (1) {
        bool in = true;
        f(i, 0, adj[rt].size(), 1) { 
            pii mv = adj[rt][i];
            tr mv_pb;
            if (mv.first) {
                tr mv_cp; mv_cp.op = 2, mv_cp.x = mv.second + 1;
                int cx = -1, cy = -1;
                f(p, 0, n, 1) f(q, 0, n, 1) if (a[rt][p][q] != a[mv.second][p][q]) cx = p + 1, cy = q + 1;
                mv_pb.op = 1, mv_pb.x = cx, mv_pb.y = cy;
                moves.pb(mv_pb), moves.pb(mv_cp);
                rt = mv.second;
                in = false;
                break;
            }
            else { mv_pb.op = 2; mv_pb.x = mv.second + 1, mv_pb.y = 0; moves.pb(mv_pb); }
        }
        if (in) break;
    }
    cout << moves.size() << nl;
    for (tr mov : moves) { 
        cout << mov.op << " " << mov.x;
        if (mov.op == 1) cout << " " << mov.y;
        cout << nl;
    }
	return 0;
}
