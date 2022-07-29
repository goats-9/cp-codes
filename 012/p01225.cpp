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
	int n, t;
	cin >> t;
	while (t--) { 
		cin >> n;
		vi a(10);
		f(j, 1, n + 1, 1) { 
			int i = j;
			while (i != 0) { 
				++a[i%10];
				i/=10;
			}
		}
		f(i, 0, 10, 1) { 
			cout << a[i];
			if (i == 9) cout << "\n";
			else cout << " ";
		}
	}
	return 0;
}
