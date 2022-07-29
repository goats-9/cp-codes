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
	vector<string> a;
	string s;
	int sz = 0;
	while (getline(cin, s)) {sz = max(sz, int(s.size())); a.pb(s);}
	int n = a.size();
	f(i, 0, sz, 1) { 
		f(j, 0, n, 1) {
			if (i < (int)a[n - 1 - j].size()) cout << a[n - 1 - j][i];
			else cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
