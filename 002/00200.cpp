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
#define MOD (int)1e9 + 7

int solve() {
    V<string> dict;
    string s;
    while (cin >> s && s != "#") dict.pb(s);
    if (!cin) return 1;
    V<bool> used(26, false);
    vi indeg(26);
    vvi adj(26, vi()); 
    f(i,0,dict.size()-1,1) {
        f(j,0,dict[i].size(),1) {
            if (dict[i][j] != dict[i+1][j]) {
                int u = dict[i][j] - 'A', v = dict[i+1][j] - 'A';
                used[u] = true;
                used[v] = true;
                adj[u].pb(v);
                ++indeg[v];
                break;
            }
        }
    }
    string ord = "";
    while (1) {
        int src = -1;
        f(i,0,26,1) if (used[i] && !indeg[i]) {src = i; break;}
        if (src == -1) break;
        ord += char('A' + src);
        for (auto v : adj[src]) --indeg[v];
        used[src] = false;
    }
    cout << ord << nl;
    return 0;
}

int main() {
    while (!solve());
	return 0;
}
