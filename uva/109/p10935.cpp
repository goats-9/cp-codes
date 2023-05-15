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
	int n;
    while (cin >> n && n) { 
		if (n == 1) {cout << "Discarded cards:\nRemaining card: 1\n"; continue;}
		vi a, del(n + 1), ds;
		int nc = n, fl = 0;
		f(i, 0, 1000, 1) a.pb(i%n + 1);
		int i = 0;
		while (nc > 1) {
			while (del[a[i]]) ++i;
			if (!fl) {ds.pb(a[i]); del[a[i]] = 1; --nc;}
			fl = (fl + 1)%2;
			++i;
		}
		int rc = 0;
		f(i, 1, n + 1, 1) if (!del[i]) {rc = i; break;}
		cout << "Discarded cards: ";
		cout << ds[0];
		f(i, 1, n - 1, 1) cout << ", " << ds[i];
		cout << nl << "Remaining card: " << rc << nl;
	}
	return 0;
}
