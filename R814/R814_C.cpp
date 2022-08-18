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
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int t, n, q;
    scanf("%d", &t);
    while (t--) { 
		cin >> n >> q;
		vi w(n), a(n);
		f(i, 0, n, 1) cin >> a[i];
		if (!(a[0] == n || a[1] == n)) {
			int mi, mx = 0;
			if (a[0] < a[1]) mi = 1, ++w[1];
			else mi = 0, ++w[0];
			f(i, 2, n, 1) { 
				if (a[i] == n) {mx = i + 1; break;}
				if (a[mi] < a[i]) mi = i, ++w[mi];
				else ++w[mi];
			}
			int a, b;
			f(i, 0, q, 1) { 
				cin >> a >> b;
				if (a == mx) cout << max(b - mx + 2, 0) << nl;
				else {
					if (w[a - 1]) { 
						if (b <= a - 2) cout << 0 << nl;
						else cout << min(w[a - 1], b - max(a - 2, 0)) << nl;
					}
					else cout << 0 << nl;
				}
			}
		} else { 
			int x = (a[0] == n) ? 1 : 2;
			int a, b;
			f(i, 0, q, 1) { 
				cin >> a >> b;
				if (a == x) cout << b << nl;
				else cout << 0 << nl;
			}
		}
	}
	return 0;
}
