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

vi dx = {-1, 0, 0, 1};
vi dy = {0, 1, -1, 0};

int main() {
	int t, n;
    scanf("%d", &t);
    f(tc, 1, t + 1, 1) { 
		cin >> n;
		V<string> grid(n);
		f(i, 0, n, 1) cin >> grid[i];
		f(i, 0, n, 1) { 
			f(j, 0, n, 1) { 
				if (grid[i][j] == '.') {
					vi nb;
					f(k, 0, 4, 1) {
						int i1 = i + dx[k], j1 = j + dy[k];
						if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && grid[i1][j1] != '.') nb.pb(grid[i1][j1] - 'A');
					}
					sort(nb.begin(), nb.end());
					int d = 0;
					f(k, 0, nb.size(), 1) if (nb[k] == d) ++d; 
					grid[i][j] = char('A' + d);
				}
			}
		}
		cout << "Case " << tc << ":" << nl;
		f(i, 0, n, 1) cout << grid[i] << nl;
	}
	return 0;
}
