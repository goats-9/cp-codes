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

int n;

void disp(vi &a) { 
	f(i, 0, n, 1) { 
		printf("%d", a[i]);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}
}

int main() {
    while (scanf("%d", &n)) { 
		if (!n) break;
		vi a(n);
		f(i, 0, n, 1) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		disp(a);
	}
	return 0;
}
