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
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> n;
		vi a(n);
		int r = n - 1, i = n - 1, l = pow(ceil(sqrt(r*(1.0))), 2) - i;
		while (i >= 0) { 
			for (int k = 0; k < r - l + 1; k++) { 
				a[i--] = l + k;
			}
			r = l - 1;
			l = pow(ceil(sqrt(r*(1.0))), 2) - i;
		}
		f(i, 0, n, 1) { 
			cout << a[i];
			if (i != n - 1) cout << " ";
			else cout << nl;
		}
	}
	return 0;
}
