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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int vis[17], n, ring[17];

vi pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void disp() { 
	f(i, 1, n + 1, 1) { 
		cout << ring[i];
		if (i == n) cout << nl;
		else cout << " ";
	}
}

void dfs(int i) { 
	if (i == n + 1) { 
		if (find(pr.begin(), pr.end(), ring[1]+ring[n]) != pr.end()) disp();
		return;
	} 
	f(j, 1, n + 1, 1) { 
		if (!vis[j] && find(pr.begin(), pr.end(), ring[i - 1] + j) != pr.end()) { 
			vis[j] = 1;
			ring[i] = j;
			dfs(i + 1);
			vis[j] = 0;
			ring[i] = 0;
		}
	}
}

int main() {
	int tc = 0;
	while (cin >> n) { 
		if (tc != 0) cout << nl;
		reset(vis, 0), reset(ring, 0);
		cout << "Case " << ++tc << ":\n";
		vis[1] = 1;
		ring[1] = 1;
		dfs(2);
	}
	return 0;
}
