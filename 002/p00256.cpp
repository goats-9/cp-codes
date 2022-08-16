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
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	stringstream s2, s4, s6, s8;
	f(k, 0, int(1e4), 1) { 
		int i = k*k;
		if (i < int(1e2) && i/int(1e1) + i%int(1e1) == k) s2 << setw(2) << setfill('0') << i << nl;
		if (i < int(1e4) && i/int(1e2) + i%int(1e2) == k) s4 << setw(4) << setfill('0') << i << nl;
		if (i < int(1e6) && i/int(1e3) + i%int(1e3) == k) s6 << setw(6) << setfill('0') << i << nl;
		if (i < int(1e8) && i/int(1e4) + i%int(1e4) == k) s8 << setw(8) << setfill('0') << i << nl;
	}
	string st2 = s2.str(), st4 = s4.str(), st6 = s6.str(), st8 = s8.str();
	int n;
    while (cin >> n) { 
		if (n == 2) cout << st2;
		else if (n == 4) cout << st4;
		else if (n == 6) cout << st6;
		else if (n == 8) cout << st8;
	}
	return 0;
}
