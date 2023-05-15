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

bool rw[15], ld[15], rd[15];
V<string> board(8);
int ans;

void backtrack(int c) { 
	if (c == 8) {++ans; return;} 
	f(i, 0, 8, 1) { 
		if (board[i][c] != '*' && rw[i] && ld[i + c] && rd[i - c + 7]) { 
			rw[i] = ld[i + c] = rd[i - c + 7] = false;
			backtrack(c + 1);
			rw[i] = ld[i + c] = rd[i - c + 7] = true;
		}
	}
}

int main() {
	ans = 0;
	f(i, 0, 8, 1) cin >> board[i];
	memset(rw, true, sizeof(rw));
	memset(rd, true, sizeof(rd));
	memset(ld, true, sizeof(ld));
	backtrack(0);
	cout << ans << nl;
	return 0;
}
