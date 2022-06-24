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
	int n, q, x, y;
	scanf("%d %d", &n, &q);
	vll a(n);
	vll b(n + 1);
	f(i, 0, n, 1) scanf("%lld", &a[i]);
	sort(a.rbegin(), a.rend());
	f(i, 1, n + 1, 1) b[i] = b[i - 1] + a[i - 1];
	f(i, 0, q, 1) { 
		scanf("%d %d", &x, &y);
		printf("%lld\n", b[x] - b[x - y]);
	}
	return 0;
}
