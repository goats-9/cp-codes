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
		int n;
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int m = INT_MAX, j = INT_MAX, mm = 0, mj = 0;
		if (n % 2) { 
			cout << "Mike\n";
		} else { 
			f(i, 0, n, 2) {
				if (m > a[i]) {m = a[i]; mm = i;}
				if (j > a[i + 1]) {j = a[i + 1]; mj = i + 1;}
			}
			if (m > j) cout << "Mike\n";
			else if (m < j) cout << "Joe\n";
			else { 
				if (mm > mj) cout << "Mike\n";
				else cout << "Joe\n";
			}
		}
	}
	return 0;
}
