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

double comb(int n, int m) { 
	double ans = 1;
	int x = min(n - m, m);
	f(i, 1, x + 1, 1) ans *= double(n - x + i)/i; 
	return ans;
}

int main() {
	int n, m;
    while (cin >> n >> m) { 
		if (!n) break;
		printf("%d things taken %d at a time is %.0lf exactly.\n", n, m, comb(n, m));
	}
	return 0;
}
