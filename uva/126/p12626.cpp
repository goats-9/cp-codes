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
#define MOD (int)1e9 + 7

int a[26];

int main() {
	string s;
	int t;
	cin >> t;
	while (t--) { 
		reset(a, 0);
		cin >> s;
		f(i, 0, s.size(), 1) ++a[s[i] - 'A'];
		int ans = INT_MAX;
		ans = min(ans, a['A' - 'A']/3);
		ans = min(ans, a['M' - 'A']);
		ans = min(ans, a['R' - 'A']/2);
		ans = min(ans, a['G' - 'A']);
		ans = min(ans, a['I' - 'A']);
		ans = min(ans, a['T' - 'A']);
		cout << ans << "\n";
	}
	return 0;
}
