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
	int n, m, q1, q2;
	cin >> n >> m;
	vll a(n), l(n), r(n);
	f(i, 0, n, 1) cin >> a[i];
	f(i, 0, n - 1, 1) { 
		r[i + 1] = max(a[i] - a[i + 1], 0LL);
		r[i + 1] += r[i];
		l[i + 1] = max(a[i + 1] - a[i], 0LL);
		l[i + 1] += l[i];
	} 
	f(i, 0, m, 1) { 
		cin >> q1 >> q2;
		if (q1 < q2) cout << r[q2 - 1] - r[q1 - 1] << "\n";
		else cout << l[q1 - 1] - l[q2 - 1] << "\n";
	} 
	return 0;
}
