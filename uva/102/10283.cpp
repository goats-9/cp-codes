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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	double R, N;
	cout << fixed << setprecision(10);
	while (cin >> R >> N) {
		if (N == 1) cout << R << " 0 0\n";
		else if (N == 2) cout << R/2 << " 0 " << 0.5*M_PI*R*R << nl;
		else {
			double theta = M_PI/N;
			double r = R/(1 + (1.0/sinl(theta)));
			double I = r*r*((N/tanl(theta)) - (N/2 - 1)*M_PI);
			double E = M_PI*(R*R - N*r*r) - I;
			cout << r << ' ' << I << ' ' << E << nl;
		}
	}
	return 0;
}
