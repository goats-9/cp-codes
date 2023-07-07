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
	int t;
	cin >> t;
	cin.ignore(1);
	while (t--) { 
		string s;
		getline(cin, s);
		stringstream ss(s);
		int w;
		vi a;
		int tot = 0;
		while (ss >> w) tot += w, a.pb(w);
		if (tot&1) {cout << "NO\n"; continue;}
		vi dp(tot+1);
		dp[0] = 1;
		int sz = a.size();
		f(i,0,sz,1) {
			vi nxt;
			f(j,0,tot+1,1) if (j-a[i] >= 0 && dp[j-a[i]]) nxt.pb(j);
			for (auto &nw : nxt) dp[nw] = 1;
		}
		if (dp[tot/2]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
