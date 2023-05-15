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

vi game, a, b;
int n;

int main() {
	cin >> n;
	while (n) { 
		a.assign(n, 0);
		b.assign(n, 0);
		f(i, 0, 6, 1) b[i] = 1;
		f(i, 0, n, 1) cin >> a[i];
		sort(a.begin(), a.end());
		f(i1, 0, n, 1) { 
			f(i2, i1 + 1, n, 1) { 
				f(i3, i2 + 1, n, 1) { 
					f(i4, i3 + 1, n, 1) { 
						f(i5, i4 + 1, n, 1) { 
							f(i6, i5 + 1, n, 1) { 
								printf("%d %d %d %d %d %d\n", a[i1], a[i2], a[i3], a[i4], a[i5], a[i6]);
							}
						}
					}
				}
			}
		}
		cin >> n;
		if (n != 0) cout << "\n";
	}
	return 0;
}
