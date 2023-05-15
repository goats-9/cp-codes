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

int n, s;

int lead(vi &a, int idx) { 
	int st = idx;
	while (st < n && !a[st]) ++st;
	return st - idx;
}

int trail(vi &a, int idx) { 
	int st = idx;
	while (st >= 0 && !a[st]) --st;
	return idx - st;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		cin >> n >> s;
		int c = 0;
		vi a(n);
		f(i, 0, n, 1) {
			cin >> a[i];
			if (a[i] == 1) ++c;
		}
		if (c < s) cout << "-1\n";
		else if (c == s) cout << "0\n";
		else { 
			int it = c - s, ans = 0, l = 0, r = n - 1;
			int x, y;
			f(i, 0, it, 1) { 
				x = lead(a, l) + 1, y = trail(a, r) + 1;
				if (x >= y) { 
					ans += y;
					r -= y;
				} else { 
					ans += x;
					l += x;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
