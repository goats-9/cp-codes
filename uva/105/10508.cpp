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
	int w, l;
	while (cin >> w >> l) {
		V<string> words(w);
		for (string &s : words) cin >> s;
		vi idx(w, -1), vis(w);
		idx[0] = 0, idx[w-1] = 1;
		vis[0] = 1, vis[1] = 1;
		f(i,1,w-1,1) {
			int ci = idx[i-1];
			f(j,2,w,1) {
				if (vis[j]) continue;
				int ans = 0;
				f(k,0,l,1) ans += (words[ci][k] != words[j][k]);
				if (ans == 1) {
					idx[i] = j;
					vis[j] = 1;
					break;
				}
			}
		}
		f(i,0,w,1) cout << words[idx[i]] << nl;
	}
	return 0;
}
