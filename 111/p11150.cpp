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
	int n;
	while (cin >> n && n) { 
		int ans = 0, f = n, e = 0;
		while (f) { 
			ans += f;
			e += f;
			f = e/3;
			e %= 3;
		}
		if (e == 2) ++ans;
		cout << ans << "\n";
	}
	return 0;
}
