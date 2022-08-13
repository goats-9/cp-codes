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

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> n;
		vi a(n), b(n + 1), minpos(n + 1, -1), maxpos(n + 1);
		f(i, 0, n, 1) { 
			cin >> a[i];
			if (minpos[a[i]] == -1) minpos[a[i]] = i;
			if (i > maxpos[a[i]]) maxpos[a[i]] = i;
		}
		int oc = -1, mx = 0;
		f(i, 1, n + 1, 1) { 
			if (minpos[i] != -1) {
				if (minpos[i] < mx) oc = max(oc, maxpos[i]);
				mx = max(mx, maxpos[i]);
			}
		}
		int ans = 0;
		f(i, 0, oc + 1, 1) { 
			if (!b[a[i]]) ++ans;
			b[a[i]] = 1;
		}
		cout << ans << nl;
	}
	return 0;
}
