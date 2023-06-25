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

int main() {
	int n;
    while (cin >> n) {
        char ch;
        int m = 0;
        vi p, val;
        stack<int> stk;
        while (cin >> ch) {
            int k;
            if (ch == '(') {
                cin >> k;
                if (cin.fail()) {
                    stk.push(-1);
                    cin.clear();
                } else {
                    val.pb(k);
                    if (!stk.empty()) {
                        int u = stk.top();
                        p.pb(u);
                    } else p.pb(-1);
                    stk.push(m++);
                }
            } else if (ch == ')') stk.pop();
            if (stk.empty()) break;
        }
        if (m == 0) {
            cout << "no\n";
            continue;
        }
        vi dp(m), vis(m);
        vvi adj(m, vi());
        f(i,1,m,1) adj[p[i]].pb(i);
        dp[0] = val[0];
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) { 
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    dp[v] = val[v] + dp[u];
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        bool fl = false;
        f(i,0,m,1) {
            if (adj[i].empty() && dp[i] == n) {
                fl = true;
                break;
            }
        }
        if (fl) cout << "yes\n";
        else cout << "no\n";
    }
	return 0;
}
