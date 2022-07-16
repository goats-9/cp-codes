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
		int n, l, r;
		cin >> n >> l >> r;
		string ans = "YES\n";
		vi a(n);
		f(i, 0, n, 1) { 
			if ((i + 1)*ceil(l*(1.0)/(i + 1)) <= r) { 
				a[i] = (i + 1)*ceil(l*(1.0)/(i + 1));
			} else { ans = "NO\n"; break; }
		}
		cout << ans;
		if (ans == "YES\n") { 
			f(i, 0, n, 1) cout << a[i] << " ";
			cout << "\n";
		}
	}
	return 0;
}
