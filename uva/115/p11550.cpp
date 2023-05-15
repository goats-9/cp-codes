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
#define MOD (int)1e9 + 7

int adj[10][100];

int main() {
	int t;
    scanf("%d", &t);
    while (t--) {
		reset(adj, 0);
		int n, m;
		cin >> n >> m;
		vector<vi> a(n, vi (m));
		f(i, 0, n, 1) f(j, 0, m, 1) cin >> a[i][j];
		int fl = 1;
		f(j, 0, m, 1) { 
			vi vert;
			f(i, 0, n, 1) if (a[i][j]) vert.pb(i);
			if (int(vert.size()) != 2 || adj[vert[0]][vert[1]]) { fl = 0; break; }
			else adj[vert[0]][vert[1]] = 1, adj[vert[1]][vert[0]] = 1;
		}
		if (fl) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
