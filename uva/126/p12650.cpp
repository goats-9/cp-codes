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
#define MOD (int)1e9 + 7

int main() {
	int n, r;
    while (cin >> n >> r) { 
		vi a(n + 1);
		int x;
		f(i, 0, r, 1) { 
			cin >> x;
			a[x] = 1;
		}
		if (n == r) cout << "*\n";
		else { 
			f(i, 1, n + 1, 1) { 
				if (!a[i]) cout << i << " "; 
			}
			cout << "\n";
		}
	}
	return 0;
}
