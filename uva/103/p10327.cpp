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

int main() {
	int n;
    while (cin >> n) { 
		vi a(n); 
		f(i, 0, n, 1) cin >> a[i];
		int ctr = 0;
		f(i, 0, n, 1) { 
			f(j, 0, n - 1 - i, 1) { 
				if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); ++ctr; }
			}
		}
		cout << "Minimum exchange operations : " << ctr << "\n";
	}
	return 0;
}
