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

int n, m;

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		cin >> n >> m;
		vector<vi> a(n, vi(m));
		vector<vector<pii>> b(n, vector<pii> (m));
		f(i, 0, n, 1) f(j, 0, m, 1) cin >> a[i][j];
		if ((n + m)%2) {
			int p = (n + m - 1)/2;
			if (a[n - 1][m - 1] == -1) b[n - 1][m - 1] = {1, 1};
			for (int i = n - 1; i >= 0; i--) { 
				for (int j = m - 1; j >= 0; j--) { 
					if (i == n - 1 && j == m - 1) continue;
					if (i != n - 1) { 
						if (j != m - 1) b[i][j] = {min(b[i][j + 1].first, b[i + 1][j].first), max(b[i][j + 1].second, b[i + 1][j].second)};
						else b[i][j] = b[i + 1][j];
					} else b[i][j] = b[i][j + 1];
					if (a[i][j] == -1) {++b[i][j].first; ++b[i][j].second;}
				}
			}
			if (b[0][0].first <= p && p <= b[0][0].second) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "NO\n";
	}
	return 0;
}
