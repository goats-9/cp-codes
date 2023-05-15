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
	int n, s;
    while (cin >> n) { 
		vi b(n);
		f(i, 0, n, 1) cin >> b[i];
		cin >> s;
		int diff = int(1e9);
		int x = 0, y = 0;
		sort(b.begin(), b.end());
		f(i, 0, n, 1) { 
			if (b[i] > s/2) break;
			int pos = lower_bound(b.begin(), b.end(), s - b[i]) - b.begin();
			if (b[pos] + b[i] == s) { 
				if (b[pos] - b[i] < diff) { 
					diff = b[pos] - b[i];
					x = b[i], y = b[pos];
				}
			}
		}
		cout << "Peter should buy books whose prices are " << x << " and " << y << ".\n\n";
	}
	return 0;
}
