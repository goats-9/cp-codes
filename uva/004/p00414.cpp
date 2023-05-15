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
		cin.ignore(1, '\n');
		vi a(n);
		string s;
		int ans = 0;
		f(i, 0, n, 1) { 
			getline(cin, s);
			f(j, 0, 25, 1) if (s[j] == ' ') ++a[i];
		}
		sort(a.begin(), a.end());
		f(i, 0, n, 1) ans += (a[i] - a[0]); 
		cout << ans << nl;
	}
	return 0;
}
