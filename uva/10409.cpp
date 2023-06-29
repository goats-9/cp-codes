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
	int tc;
	while (cin >> tc && tc) {
		int t = 1, n = 2, w = 3;
		f(i,0,tc,1) {
			string s;
			cin >> s;
			if (s[0] == 'n') {
				int k = 7 - n;
				n = t;
				t = k;
			} else if (s[0] == 'e') {
				int k = 7 - t;
				t = w;
				w = k;
			} else if (s[0] == 'w') {
				int k = 7 - w;
				w = t;
				t = k;
			} else {
				int k = 7 - t;
				t = n;
				n = k;
			}
		}
		cout << t << nl;
	}
	return 0;
}
