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
#define N 1000000007

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n, x;
		cin >> n;
		vi pos(n);
		f(i, 0, n, 1) { 
			cin >> x;
			pos[x] = i;
		}
		ll ans = 1;
		int l = min(pos[0], pos[1]);
		int r = max(pos[0], pos[1]);
		int m = r - l - 1;
		f(i, 2, n, 1) { 
			if (l < pos[i] && pos[i] < r) ans *= m;
			else if (pos[i] < l) l = pos[i];
			else r = pos[i];
			m = r - l - i;
			ans %= N;
		}
		cout << ans << "\n";
	}
	return 0;
}
