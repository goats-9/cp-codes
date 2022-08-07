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
	int t, n, k;
    scanf("%d", &t);
    f(j, 1, t + 1, 1) { 
		cin >> n >> k;
		vll x(n), y(n);
		f(i, 0, n, 1) cin >> x[i];
		f(i, 0, n, 1) { cin >> y[i]; y[i] -= x[i]; }
		sort(y.begin(), y.end());
		ll pr = 0;
		f(i, 0, k, 1) { 
			if (y[i] < 0) y[i] = 0;
			else break;
		}
		f(i, 0, n, 1) pr += y[i];
		cout << "Case " << j << ": ";
		if (pr > 0) cout << pr << nl;
		else cout << "No Profit" << nl;
	}
	return 0;
}
