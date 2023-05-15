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
		int n, x, y;
		cin >> n;
		vi a(n);
		if (n == 1) cout << "0\n";
		else if (n == 2) {cin >> x >> y; cout << "1\n";}
		else { 
			f(i, 0, n - 1, 1) { 
				cin >> x >> y;
				++a[x - 1];
				++a[y - 1];
			}
			sort(a.rbegin(), a.rend());
			cout << a[0] - 1 << "\n";
		}
	}
	return 0;
}
