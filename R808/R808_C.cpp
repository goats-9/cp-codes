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
		int n, q;
		cin >> n >> q;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		string ans = "\n";
		int cur = 0;
		f(i, 0, n, 1) {
			if (cur < q) { 
				ans = "1" + ans;
				if (a[n - i - 1] > cur) ++cur;
			} else { 
				if (a[n - i - 1] <= cur) ans = "1" + ans;
				else ans = "0" + ans;
			}
		}
		cout << ans;
	}
	return 0;
}
