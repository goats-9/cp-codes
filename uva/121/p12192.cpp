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

int main() {
	int n, m, q, l, r;
	while (cin >> n >> m && n) { 
		vector<vi> field(n, vi(m));
		f(i, 0, n, 1) f(j, 0, m, 1) cin >> field[i][j];
		cin >> q;
		f(i, 0, q, 1) { 
			cin >> l >> r;
			int ans = 0;
			f(j, 0, n, 1) { 
				int x1 = lower_bound(field[j].begin(), field[j].end(), l) - field[j].begin();
				int x2 = upper_bound(field[j].begin(), field[j].end(), r) - field[j].begin();
				if (x1 == x2) continue;
				int i = 0;
				while (x1 + i < min(m, x2 + 1) && j + i < n) { 
					if (field[j + i][x1 + i] <= r) ans = max(ans, i + 1);
					++i;
				}
			}
			cout << ans << "\n";
		}
		cout << "-\n";
	}
	return 0;
}
