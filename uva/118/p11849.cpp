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
    while (cin >> n >> m && n) { 
		set<int> c1, c2;
		vi a1(n), a2(m), a(n + m);
		f(i, 0, n, 1) cin >> a1[i];
		c1.insert(a1.begin(), a1.end());
		f(i, 0, m, 1) cin >> a2[i];
		c2.insert(a2.begin(), a2.end());
		vi::iterator it = set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), a.begin());
		cout << it - a.begin() << "\n";
	}
	return 0;
}
