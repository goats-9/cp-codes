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
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n, m;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;
		if (n < m) cout << "NO\n";
		else if (n == m) {
			if (a == b) cout << "YES\n";
			else cout << "NO\n";
		} else { 
			int fl = 1;
			for (int i = m - 1, j = n - 1; i >= 1; i--, j--) {
				if (b[i] != a[j]) { 
					cout << "NO\n";
					fl = 0;
					break;
				}  
			}
			if (fl) { 
				int o = 0, z = 0;
				f(i, 0, n - m + 1, 1) a[i] == '0' ? z = 1 : o = 1;
				if ((b[0] == '0' && z) || (b[0] == '1' && o)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}
