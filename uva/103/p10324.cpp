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
	string s;
	int q, a, b, tc = 0;
	while (getline(cin, s) && s != "") { 
		vi chg;
		cout << "Case " << ++tc << ":\n";
		f(i, 1, s.size(), 1) if (s[i] != s[i - 1]) chg.pb(i);
		cin >> q;
		f(i, 0, q, 1) { 
			cin >> a >> b;
			int l = min(a, b), r = max(a, b);
			if (upper_bound(chg.begin(), chg.end(), l) != upper_bound(chg.begin(), chg.end(), r)) cout << "No\n";
			else cout << "Yes\n";
		}
		cin.ignore(1, '\n');
	}
	return 0;
}
