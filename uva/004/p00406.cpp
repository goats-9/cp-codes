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

bool isPrime(int n) { 
	f(i, 2, sqrt(n) + 1, 1) if (!(n%i)) return false;
	return true;
}

int main() {
	vi pr;
	f(i, 1, 1001, 1) if (isPrime(i)) pr.pb(i);
	int n, c;
    while (cin >> n >> c) { 
		int len = upper_bound(pr.begin(), pr.end(), n) - pr.begin(), l = 0, r = 0;
		if (len%2) l = max(len/2 + 1 - c, 0), r = min(len/2 + c, len);
		else l = max(len/2 - c, 0), r = min(len/2 + c, len); 
		cout << n << " " << c << ": " << pr[l];
		f(i, l + 1, r, 1) cout << " " << pr[i];
		cout << nl << nl;
	}
	return 0;
}
