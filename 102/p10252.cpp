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
	string a, b;
	while (getline(cin, a)) { 
		getline(cin, b);
		vi a_let(26), b_let(26), c(26);
		f(i, 0, a.size(), 1) a_let[a[i] - 'a']++;
		f(i, 0, b.size(), 1) b_let[b[i] - 'a']++;
		f(i, 0, 26, 1) c[i] = min(a_let[i], b_let[i]);
		f(i, 0, 26, 1) f(j, 0, c[i], 1) cout << char(i + 'a');
		cout << "\n";
	}
	return 0;
}
