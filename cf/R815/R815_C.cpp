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

vi dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vi dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	int t, n, m;
    scanf("%d", &t);
    while (t--) { 
		cin >> n >> m;
		V<string> a(n);
		int ctr = 0;
		f(i, 0, n, 1) { 
			cin >> a[i];
			f(j, 0, m, 1) if (a[i][j] == '1') ++ctr;
		}
		int fl = 0;
		int db = 0;
		f(i, 0, n, 1) { 
			f(j, 0, m, 1) { 
				if (a[i][j] == '0') {
					fl = 1;
					f(k, 0, 8, 1) { 
						int cx = i + dx[k], cy = j + dy[k];
						if (0 <= cx && cx < n && 0 <= cy && cy < m && a[cx][cy] == '0') db = 1;
					}
				}
			}
		}
		if (db) cout << ctr << nl;
		else if (fl) cout << max(ctr - 1, 0) << nl;
		else cout << max(ctr - 2, 0) << nl;
	}
	return 0;
}
