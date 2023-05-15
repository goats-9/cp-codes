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
	int n, t;
    scanf("%d", &t);
    while (t--) { 
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		sort(a.begin(), a.end());
		int fl = 1;
		if (a[0]%10 == 0) { 
			f(i, 1, n, 1) if (a[i] != a[0]) {fl = 0; break;} 
		} else if (a[0]%10 == 5) { 
			f(i, 1, n, 1) if (!(a[i] - a[0] == 0 || a[i] - a[0] == 5)) {fl = 0; break;}
		} else { 
			vi a1 = {1, 2, 4, 8, 13, 16, 17, 19};
			vi a2 = {3, 6, 7, 9, 11, 12, 14, 18};
			int k = a[0]%20;
			if (find(a1.begin(), a1.end(), k) != a1.end()) { 
				f(i, 1, n, 1) if (find(a1.begin(), a1.end(), a[i]%20) == a1.end()) {fl = 0; break;}
			} else { 
				f(i, 1, n, 1) if (find(a2.begin(), a2.end(), a[i]%20) == a2.end()) {fl = 0; break;}
			}
		}
		if (fl) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
