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
	vi s(3);
	while (cin >> s[0] >> s[1] >> s[2] && s[0]) { 
		sort(s.begin(), s.end());
		if (s[0]*s[0] + s[1]*s[1] == s[2]*s[2]) cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}
