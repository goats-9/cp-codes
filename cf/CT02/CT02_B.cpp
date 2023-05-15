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

bool out(int p, int x, int l, int r) { return (p + x < l || p - x > r); }

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n, x;
		cin >> n >> x;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int l = a[0] - x, r = a[0] + x, ctr = 0;
		f(i, 1, n, 1) { 
			if (out(a[i], x, l, r)) { 
				++ctr;
				l = a[i] - x;
				r = a[i] + x;
			} else l = max(l, a[i] - x), r = min(a[i] + x, r);
		}
		cout << ctr << "\n";
	}
	return 0;
}
