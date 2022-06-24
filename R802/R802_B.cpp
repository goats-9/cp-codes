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
		int n;
		string s;
		cin >> n >> s;
		if (s[0] != '9') {
			string num(n, '9');
			f(i, 0, n, 1) {
				num[i] = num[i] - s[i] + '0';
			}
			cout << num << "\n";
		} else { 
			string num(n + 1, '1');
			int c = 0;
			f(i, 1, n + 1, 1) { 
				int ans = num[n + 1 - i] - s[n - i] - c;
				if (ans < 0) { 
					ans += 10;
					c = 1;
				} else c = 0;
				num[n + 1 - i] = ans + '0';
			}
			cout << num.substr(1, n) << "\n";
		}
	}
	return 0;
}
