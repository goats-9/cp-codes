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
		int n, k;
		cin >> n >> k;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int m = ceil(n/2.0) - 1;
		if (k == 1) cout << m << "\n";
		else { 
			int ctr = 0;
			f(i, 1, n - 1, 1) { 
				if (a[i] > a[i - 1] + a[i + 1]) ++ctr;
			}	
			cout << ctr << "\n";
		}
	}
	return 0;
}
