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

int nod(int n) { 
	int ctr = 0;
	f(i, 1, sqrt(n) + 1, 1) if (!(n%i)) ctr += 2;
	int r = sqrt(n);
	if (r*r == n) --ctr;
	return ctr;
}

int main() {
	vi a;
	int k = 1;
	a.pb(k);
	while (k <= 1000000) {
		k += nod(k);
		a.pb(k);
	}
	int t, n, m;
    scanf("%d", &t);
    f(k, 1, t + 1, 1) { 
		cin >> n >> m;
		cout << "Case " << k << ": " << upper_bound(a.begin(), a.end(), m) - lower_bound(a.begin(), a.end(), n) << "\n";
	}
	return 0;
}
