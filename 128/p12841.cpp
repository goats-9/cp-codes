#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < (int)b; i = i + (int)j)
#define pb push_back
#define N (1 << 15)
#define LSOne(s) (s & (-s))
#define reset(a, b) memset(a, int(b), sizeof(a))

char x, y;
vector<char> a(15);
int n, m, c[26];
bool memo[15][N];
vector<vi> adj;
stack<int> stk;

bool tsp(int u, int mask) { 
	bool &ans = memo[u][mask];	
	if (mask == 0) return ans = (u == n - 1);
	int l;
	if (ans) return true;
	f(i, 0, adj[u].size(), 1) { 
		l = adj[u][i];
		if ((mask & (1 << l)) && tsp(l, mask^(1 << l))) {stk.push(u); return ans = true;}
	}
	return ans = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
	cin >> t;
    f(k, 1, t + 1, 1) {
		cin >> n >> m;
		adj.assign(15, {});
		a.assign(15, 0);
		reset(memo, false), reset(c, 0);
		f(i, 0, n, 1) cin >> a[i];
		sort(a.begin() + 1, a.begin() + n - 1);
		f(i, 0, n, 1) c[a[i] - 'A'] = i;
		f(i, 0, m, 1) { 
			cin >> x >> y;
			adj[c[x - 'A']].pb(c[y - 'A']), adj[c[y - 'A']].pb(c[x - 'A']);
		}
		f(i, 0, n, 1) sort(adj[i].begin(), adj[i].end());
		cout << "Case " << k << ": ";
		if (tsp(0, (1 << n) - 2)) { 
			string s = "";
			while (!stk.empty()) {
				s += a[stk.top()];
				stk.pop();
			}
			cout << s << a[n - 1] << "\n";
		} else cout << "impossible\n";
	}
    return 0;
}
