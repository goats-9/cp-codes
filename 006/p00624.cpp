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
	int n, m;
    while (cin >> n >> m) { 
		vi a(m);
		f(i, 0, m, 1) cin >> a[i];
		int mx = 0, sm = 0, sb = 0;
		f(i, 0, (1 << m), 1) {
			sm = 0;
			f(j, 0, m, 1) if (i & (1 << j)) sm += a[j];
			if (sm > mx && sm <= n) mx = sm, sb = i;
		}
		f(i, 0, m, 1) if (sb & (1 << i)) cout << a[i] << " ";
		cout << "sum:" << mx << "\n";
	}
	return 0;
}
