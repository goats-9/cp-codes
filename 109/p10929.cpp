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
	string s;
	int o, e;
	while (cin >> s && s != "0") { 
		o = 0, e = 0;
		f(i, 0, s.size(), 1) (i%2) ? o += (s[i] - '0') : e += (s[i] - '0');
		cout << s << " is";
		if((o - e)%11) cout << " not";
		cout << " a multiple of 11.\n";
	}
	return 0;
}
