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
	int n;
    while (cin >> n && n) {
		vi a(n);
		while (cin >> a[0] && a[0]) { 
			f(i, 1, n, 1) cin >> a[i];
			int mx = a[0], i = 1, fl = 1;
			while (i < n) { 
				if (a[i] > a[i - 1] && a[i] < mx) {fl = 0; break;}
				else if (a[i] > a[i - 1] && a[i] > mx) mx = a[i];
				++i;
			}
			if (fl) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << "\n";
	}
	return 0;
}
