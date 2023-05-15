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

int h[10][10], v[10][10];

int main() {
	int n, m, x, y, tc = 0;
	char ch;
    while (cin >> n >> m) {
		reset(h, 0), reset(v, 0);
		if (tc) { 
			cout << "\n**********************************\n\n";
		}
		f(i, 0, m, 1) { 
			cin >> ch >> x >> y;
			if (ch == 'H') h[x][y] = 1;
			else v[y][x] = 1; 
		}
		cout << "Problem #" << ++tc << nl << nl;
		int ans = 0;
		f(i, 1, n, 1) {
			int ctr = 0;
			f(j, 1, n - i + 1, 1) { 
				f(k, 1, n - i + 1, 1) { 
					int fl = 1;
					f(a, 0, i, 1) if (!(h[j][k + a] && h[j + i][k + a] && v[j + a][k] && v[j + a][k + i])) {fl = 0; break;}
					ctr += fl;
				}
			}
			ans += ctr;
			if (ctr) cout << ctr << " square (s) of size " << i << nl;
		}
		if (!ans) cout << "No completed squares can be found.\n";
	}
	return 0;
}
