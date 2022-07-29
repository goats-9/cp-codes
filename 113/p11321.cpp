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

int n, m;

int main() {
	while (cin >> n >> m && n) { 
		cout << n << " " << m << "\n";
		vi v(n);
		f(i, 0, n, 1) cin >> v[i];
		sort(v.begin(), v.end(), [](int a, int b) { 
			if (a%m == b%m) { 
				if (a%2) { 
					if (b%2) return a > b;
					else return true;
				} else { 
					if (b%2) return false;
					else return b > a;
				}
			} else return a%m < b%m;		
		});
		f(i, 0, n, 1) cout << v[i] << "\n";
	}
	cout << "0 0\n";
	return 0;
}
