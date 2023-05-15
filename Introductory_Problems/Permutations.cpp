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
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int n;
	cin >> n;
	if (n == 1) cout << "1\n";
	else if (n < 4) cout << "NO SOLUTION\n";
	else if (n == 4) cout << "2 4 1 3\n";
	else { 
		cout << 1;
		f(i, 3, n + 1, 2) cout << " " << i;
		f(i, 2, n + 1, 2) cout << " " << i;
		cout << nl;
	}
	return 0;
}
