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
	string s;
	while (getline(cin, s)) { 
		string ans = "";
		string home = "";
		int fl = 0;
		f(i, 0, s.size(), 1) { 
			if (s[i] == '[') {
				fl = 1;
				ans = home + ans;
				home = "";
			} else if (s[i] == ']') {
				fl = 0;
				ans = home + ans;
				home = "";
			} else { 
				if (fl) home += s[i];
				else ans += s[i];
			}
		}
		cout << home + ans << "\n";
	}
	return 0;
}
