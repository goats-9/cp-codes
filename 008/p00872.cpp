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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7

int indeg[32], c[32], sz, vis[32], ctr;
vector<vi> adj;
vector<char> a;

void disp(vi &v) { 
	f(i, 0, sz, 1) { 
		cout << a[v[i]];
		if (i == sz - 1) cout << "\n";
		else cout << " ";
	}
}

void allTopo(vi order) { 
	if (int(order.size()) == sz) {disp(order); ++ctr;}
	f(i, 0, sz, 1) { 
		if (!indeg[i] && !vis[i]) { 
			f(j, 0, adj[i].size(), 1) --indeg[adj[i][j]];
			vis[i] = 1;
			order.pb(i);
			allTopo(order);
			order.pop_back();
			vis[i] = 0;
			f(j, 0, adj[i].size(), 1) ++indeg[adj[i][j]];
		}
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore(1, '\n');
    while (t--) { 
		reset(indeg, 0), reset(vis, 0), reset(c, 0);
		adj.assign(32, {});
		string s;
		getline(cin, s);
		getline(cin, s);
		sz = (s.size() + 1)/2;
		a.assign(sz, 0);
		ctr = 0;
		vi order;
		f(i, 0, sz, 1) a[i] = s[2*i];
		getline(cin, s);
		sort(a.begin(), a.end());
		f(i, 0, sz, 1) c[a[i] - 'A'] = i;
		f(i, 0, (s.size() + 1)/4, 1) {adj[c[s[4*i] - 'A']].pb(c[s[4*i + 2] - 'A']); ++indeg[c[s[4*i + 2] - 'A']];}
		allTopo(order);
		if (ctr == 0) cout << "NO\n";
		if (t != 0) cout << "\n";
	}	
	return 0;
}
