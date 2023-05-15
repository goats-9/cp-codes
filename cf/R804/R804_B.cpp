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

int n, m;

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		cin >> n >> m;
		vector<vi> a(n, vi(m));
		f(i, 0, n, 2) { 
			f(j, 0, m, 2) { 
				if ((i/2 + j/2)%2) { 
					a[i][j] = 0;
					a[i + 1][j] = 1;
					a[i + 1][j + 1] = 0;
					a[i][j + 1] = 1;
				}
				else { 
					a[i][j] = 1;
					a[i + 1][j] = 0;
					a[i + 1][j + 1] = 1;
					a[i][j + 1] = 0;
				}
			}
		}
		f(i, 0, n, 1) { 
			f(j, 0, m, 1) { 
				cout << a[i][j];
				if (j != m - 1) cout << " ";
				else cout << "\n";
			}
		}
	}
	return 0;
}
