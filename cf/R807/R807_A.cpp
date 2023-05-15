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
		int n, x;
		cin >> n >> x;
		vi h(2*n);
		f(i, 0, 2*n, 1) cin >> h[i];
		sort(h.begin(), h.end());
		int ans = 1;
		f(i, 0, n, 1) { 
			if (h[i + n] - h[i] < x) {ans = 0; break;}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
