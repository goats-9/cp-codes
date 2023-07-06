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
	int n; cin >> n;
	V<string> a(n);
	V<string> song = {
		"Happy",
		"birthday",
		"to",
		"you",
	};
	string name = "Rujia";
	for (auto &x : a) cin >> x;
	vi vis(n);
	int tot = 0, idx = 0;
	while (tot != n) {
		f(k,0,4,1) {
			if (k == 2) song[3] = name;
			f(i,0,4,1) {
				cout << a[idx] << ": " << song[i] << nl;
				tot += (1 - vis[idx]);
				vis[idx] = 1;
				idx = (idx + 1) % n;
			}
			if (k == 2) song[3] = "you";
		}
	}
	return 0;
}
