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
	int t;
	ll a, b, c, d;
    scanf("%d", &t);
    while (t--) { 
		cin >> a >> b >> c >> d;
		if (double(a)/b == double(c)/d) cout << "0\n";
		else if (a == 0 || c == 0) cout << "1\n";
		else { 
			double x = double(a*d)/(b*c);
			double y = (1.0)/x;
			if (x == int(x) || y == (int)y) cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}
