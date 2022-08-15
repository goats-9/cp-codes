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
#define INF (int)1e9

int main() {
	int t, n;
    scanf("%d", &t);
    f(m, 1, t + 1, 1) { 
		cin >> n;
		vvi a(n, vi(n, INF));
		vvi c(n, vi(n));
		f(j, 1, n, 1) { 
			f(i, 0, j, 1) { 
				cin >> a[i][j];
				a[j][i] = a[i][j];
			}
		}
		int fl = 0, ctr = 0;
		f(i, 0, n, 1) { 
			f(j, i + 1, n, 1) { 
				int cab = 1;
				f(k, 0, n, 1) { 
					if (a[i][j] > a[i][k] + a[k][j]) {fl = 1; break;}
					else if (a[i][j] == a[i][k] + a[k][j]) cab = 0;
				}
				c[i][j] = cab;
				ctr += cab;
			}
		}
		cout << "Case #" << m << ":\n";
		if (fl) cout << "Need better measurements.\n";
		else { 
			cout << ctr << nl;
			f(i, 0, n, 1) f(j, i + 1, n, 1) if (c[i][j]) cout << i + 1 << " " << j + 1 << " " << a[i][j] << nl;
		}
		cout << nl;
	}
	return 0;
}
