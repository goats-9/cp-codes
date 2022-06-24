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

void solve(vi &a) { 
	f(i, 0, 10, 1) { 
		f(j, i, 10, 1) { 
			f(k, j, 10, 1) { 
				if ((i + j + k)%10 == 3) { 
					if (i == j) {
						if (j == k && a[i] >= 3) {cout << "YES\n"; return;}
						else if (a[i] >= 2 && a[k]) {cout << "YES\n"; return;}
					} else { 
						if (j == k && a[i] && a[j] >= 2) {cout << "YES\n"; return;}
						else if (a[i] && a[j] && a[k]) {cout << "YES\n"; return;}
					}
				}
			}
		}
	}
	cout << "NO\n";
	return;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n, x;
		cin >> n;
		vi a(10);
		f(i, 0, n, 1) { 
			cin >> x;
			++a[x%10]; 
		}
		solve(a);
	}
	return 0;
}
