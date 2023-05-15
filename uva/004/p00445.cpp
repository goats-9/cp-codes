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

bool isdigit(char x) { return (x >= '0') && (x <= '9');}

int main() {
	string s;
	while (getline(cin, s)) {
		int i = 0, d = 0, n = s.size();
		while (i < n) {
			if (isdigit(s[i])) { 
				int k = 0;
				while (i + k < n && isdigit(s[i + k])) { d += (s[i + k] - '0'); ++k; }
				i += k;
			} else if (s[i] == '!') { cout << "\n"; ++i; }
			else if (s[i] == 'b') { 
				f(j, 0, d, 1) cout << " ";
				d = 0;
				++i;
			} else { 
				f(j, 0, d, 1) cout << s[i];
				d = 0;
				++i;
			}
		}
		cout << "\n";
	}
	return 0;
}
