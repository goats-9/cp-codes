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
#define MOD 1e9 + 7

int main() {
	mii fr;
	vi ord;
	int n;
	while (cin >> n) { 
		if (find(ord.begin(), ord.end(), n) == ord.end()) { 
			ord.pb(n);
			fr[n] = 1;
		} else ++fr[n];
	}
	f(i, 0, ord.size(), 1) cout << ord[i] << " " << fr[ord[i]] << "\n";
	return 0;
}
