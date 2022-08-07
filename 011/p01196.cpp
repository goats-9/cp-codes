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
		V<pii> b(n);
		f(i, 0, n, 1) cin >> b[i].first >> b[i].second;
		sort(b.begin(), b.end());
		vi L(n);
		int k = 0;
		f(i, 0, n, 1) { 
			int pos = upper_bound(L.begin(), L.begin() + k, b[i].second) - L.begin();
			L[pos] = b[i].second;
			if (pos == k) ++k;
		}
		cout << k << "\n";
	}
	cout << "*\n";
	return 0;
}
