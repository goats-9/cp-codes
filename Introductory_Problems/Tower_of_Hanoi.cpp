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

int main() {
	V<V<pii>> moves(16);
	moves[0].pb(pii(1, 3));
	f(i, 1, 16, 1) { 
		f(j, 0, moves[i - 1].size(), 1) { 
			pii next = moves[i - 1][j];
			if (next.first == 3) next.first = 2;
			else if (next.first == 2) next.first = 3;
			if (next.second == 3) next.second = 2;
			else if (next.second == 2) next.second = 3;
			moves[i].pb(next);
		}
		moves[i].pb(pii(1, 3));
		f(j, 0, moves[i - 1].size(), 1) { 
			pii next = moves[i - 1][j];
			if (next.second == 1) next.second = 2;
			else if (next.second == 2) next.second = 1;
			if (next.first == 1) next.first = 2;
			else if (next.first == 2) next.first = 1;
			moves[i].pb(next);
		}
	}
	int n;
	cin >> n;
	cout << moves[n - 1].size() << nl;
	f(i, 0, moves[n - 1].size(), 1) cout << moves[n - 1][i].first << " " << moves[n - 1][i].second << nl;
	return 0;
}
