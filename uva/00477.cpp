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
#define INF 9999.9

int main() {
    char ch;
    V<V<double>> figs;
    while (cin >> ch && ch != '*') {
        if (ch == 'r') {
            double x1, x2, y1, y2;
            cin >> x1 >> y2 >> x2 >> y1;
            figs.pb({x1, x2, y1, y2});
        } else {
            double x, y, r;
            cin >> x >> y >> r;
            figs.pb({x, y, r});
        }
    }
    double u, v;
    int pt = 0;
    while (cin >> u >> v && !(u == INF && v == INF)) {
        pt++;
        int ctr = 0, t = 0;
        for (auto fig : figs) {
            t++;
            int sz = fig.size();
            if (sz == 4) {
                double x1 = fig[0], x2 = fig[1], y1 = fig[2], y2 = fig[3];
                if ((x1-u)*(x2-u) < 0.0 && (y1-v)*(y2-v) < 0.0) {
                    ++ctr;
                    cout << "Point " << pt << " is contained in figure " << t << nl;
                }
            } else {
                double x = fig[0], y = fig[1], r = fig[2];
                if (pow(x-u,2) + pow(y-v,2) < pow(r,2)) {
                    ++ctr;
                    cout << "Point " << pt << " is contained in figure " << t << nl;
                }
            }
        }
        if (!ctr) cout << "Point " << pt << " is not contained in any figure\n";
    }
	return 0;
}
