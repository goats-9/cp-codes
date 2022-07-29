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

int main() {
	int t;
    scanf("%d", &t);
    f(k, 1, t + 1, 1) { 
		string s;
		cin >> s;
		int n = s.size();
		ll ans = 0;
		if (n%2 && s[n/2] == '1') ans = 1;
		int m = n/2 - 1;
		for (int i = m; i >= 0; i--) { 
			bool cl = (s[i] == '1');
			bool cr = (s[n - 1 - i] == '1');
			ans = 4*ans;
			ans %= MOD;
			if (cl && cr) ans += 3;
			else if (cl ^ cr) ans += 2;
			ans %= MOD; 
		}
		cout << "Case #" << k << ": " << ans << "\n";
	}
	return 0;
}
