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
	int n, h, w, l;
	while (cin >> n && n) { 
		vector<pii> a(n);
		f(i, 0, n, 1) {
			cin >> l >> w >> h;
			a[i].first = h;
			a[i].second = l*w*h;
		}
		sort(a.rbegin(), a.rend());
		cout << a[0].second << "\n";
	}
	return 0;
}
