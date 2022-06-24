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
		int n, m;
		cin >> n >> m;
		vector<vi> a(n, vi (m));
		int mx = INT_MIN, x = 0, y = 0;
		f(i, 0, n, 1) { 
			f(j, 0, m, 1) { 
				cin >> a[i][j];
				if (a[i][j] > mx) { 
					mx = a[i][j];
					x = i;
					y = j;
				}
			}
		}
		printf("%d\n", max(x + 1, n - x)*max(y + 1, m - y));
	}
	return 0;
}
