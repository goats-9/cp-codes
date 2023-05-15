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

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n, m;
		cin >> n >> m;
		vi a(n), b(m);
		f(i, 0, n, 1) cin >> a[i];
		f(i, 0, n, 1) { 
			int x = min(m - a[i], a[i] - 1), y = m - 1 - x;
			if (!b[x]) b[x] = 1;
			else if (!b[y]) b[y] = 1;
		}
		f(i, 0, m, 1) { 
			if (b[i]) cout << 'A';
			else cout << 'B';
		}
		cout << "\n";
	}
	return 0;
}
