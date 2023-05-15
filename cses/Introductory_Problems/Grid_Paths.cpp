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

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
V<char> dc = {'L', 'U', 'D', 'R'};
bool vis[7][7]; 
int ans;
string s;
char pc;

bool inBounds(int i, int j) { return (0 <= i && i < 7 && 0 <= j && j < 7); }

bool can_vis(int i, int j) { return (inBounds(i, j) && !vis[i][j]); }

bool partitioned(int i, int j) { 
	if (pc == 'U' && !can_vis(i, j - 1) && can_vis(i + 1, j) && can_vis(i - 1, j)) return true;
	if (pc == 'D' && !can_vis(i, j + 1) && can_vis(i + 1, j) && can_vis(i - 1, j)) return true;
	if (pc == 'L' && !can_vis(i - 1, j) && can_vis(i, j + 1) && can_vis(i, j - 1)) return true;
	if (pc == 'R' && !can_vis(i + 1, j) && can_vis(i, j + 1) && can_vis(i, j - 1)) return true;
	return false;
}

void backtrack(int i, int j, int u) { 
	//if (!inBounds(i, j) || vis[i][j]) return;
	//if (vis[i][j]) return;
	//if (u > 1 && partitioned(i, j)) return;
	if (i == 0 && j == 6) { 
		if (u == 48) ++ans;
		return;
	}
	if (u == 48) return;
	vis[i][j] = true;
	if (s[u] == '?' || s[u] == 'L') {pc = 'L'; if (can_vis(i - 1, j) && !partitioned(i - 1, j)) backtrack(i - 1, j, u + 1);}
	if (s[u] == '?' || s[u] == 'R') {pc = 'R'; if (can_vis(i + 1, j) && !partitioned(i + 1, j)) backtrack(i + 1, j, u + 1);}
	if (s[u] == '?' || s[u] == 'U') {pc = 'U'; if (can_vis(i, j - 1) && !partitioned(i, j - 1)) backtrack(i, j - 1, u + 1);}
	if (s[u] == '?' || s[u] == 'D') {pc = 'D'; if (can_vis(i, j + 1) && !partitioned(i, j + 1)) backtrack(i, j + 1, u + 1);}
	vis[i][j] = false;
}

int main() {
	cin >> s;
	ans = 0;
	memset(vis, false, sizeof(vis));
	backtrack(0, 0, 0);
	cout << ans << nl;
	return 0;
}
