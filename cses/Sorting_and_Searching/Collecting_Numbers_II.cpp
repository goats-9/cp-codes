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
	int n, m, x, y;
	cin >> n >> m;
	vi a(n), b(n);
	f(i, 0, n, 1) { cin >> a[i]; b[a[i] - 1] = i; }
	int ans = 0, i = 0;
	while (i < n) { 
		int k = 0;
		while (i + k + 1 < n && b[i + k + 1] > b[i + k]) ++k;
		i += (k + 1);
		++ans;
	}
	f(i, 0, m, 1) {
		cin >> x >> y;
		int p = a[x - 1] - 1, q = a[y - 1] - 1, r = min(p, q), s = max(p, q);
		if (s == r + 1) { 
			(b[r] < b[s]) ? ++ans : --ans;
			if (r != 0) { 
				if (b[r - 1] > b[r] && b[r - 1] < b[s]) --ans;
				if (b[r - 1] < b[r] && b[r - 1] > b[s]) ++ans;
			}
			if (s != n - 1) { 
				if (b[s] < b[s + 1] && b[r] > b[s + 1]) ++ans;
				if (b[s] > b[s + 1] && b[r] < b[s + 1]) --ans;
			}
		} else { 
			if (r != 0) { 
				if (b[r - 1] < b[r] && b[r - 1] > b[s]) ++ans;
				if (b[r - 1] > b[r] && b[r - 1] < b[s]) --ans;
			}
			if (r != n - 1) { 
				if (b[r] < b[r + 1] && b[s] > b[r + 1]) ++ans;
				if (b[r] > b[r + 1] && b[s] < b[r + 1]) --ans;
			}
			if (s != 0) { 
				if (b[s - 1] < b[s] && b[s - 1] > b[r]) ++ans;
				if (b[s - 1] > b[s] && b[s - 1] < b[r]) --ans;
			}
			if (s != n - 1) { 
				if (b[s] < b[s + 1] && b[r] > b[s + 1]) ++ans;
				if (b[s] > b[s + 1] && b[r] < b[s + 1]) --ans;
			}
		}
		cout << ans << nl;
		swap(b[r], b[s]);
		swap(a[x - 1], a[y - 1]);
	}
	return 0;
}
