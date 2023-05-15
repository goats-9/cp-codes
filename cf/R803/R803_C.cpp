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
		int n, pos = 0, neg = 0;
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) {
			cin >> a[i];
			if (a[i] > 0) ++pos;
			else if (a[i] < 0) ++neg;
		}
		if (pos > 2 || neg > 2) cout << "NO\n";
		else { 
			sort(a.begin(), a.end());
			if (pos == 0) { 
				if (neg == 2) cout << "NO\n";
				else cout << "YES\n";
			} else if (pos == 1) { 
				if (neg == 0) cout << "YES\n";
				else if (neg == 1) { 
					if (a[0] + a[n - 1] == 0) cout << "YES\n";
					else cout << "NO\n";
				} else { 
					if (n > 3) cout << "NO\n";
					else {
						if (a[0] + a[2] == 0 || a[1] + a[2] == 0) cout << "YES\n";
						else cout << "NO\n";
					}
				}
			} else { 
				if (neg == 0) cout << "NO\n";
				else if (neg == 1) { 
					if (n > 3) cout << "NO\n";
					else { 
						if (a[0] + a[2] == 0 || a[0] + a[1] == 0) cout << "YES\n";
						else cout << "NO\n";
					}
				} else { 
					if (n > 4) cout << "NO\n";
					else { 
						int s = a[0] + a[1] + a[2] + a[3];
						int ans = 1;
						f(i, 0, 4, 1) { 
							if (find(a.begin(), a.end(), s - a[i]) == a.end()) {ans = 0; break;}
						}
						if (ans) cout << "YES\n";
						else cout << "NO\n";
					}
				}
			}
		}
	}
	return 0;
}
