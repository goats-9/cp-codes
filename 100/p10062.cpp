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

struct mypii { 
	int x, y;
	bool operator< (mypii &b) const { 
		if (x == b.x) return y > b.y;
		return x < b.x;
	}
};

int main() {
	string s;
	int tc = 0;
    while (getline(cin, s)) { 
		if (tc++ != 0) cout << nl;
		int n = s.size();
		mii freq;
		f(i, 0, n, 1) { 
			if (freq.find(int(s[i])) == freq.end()) freq[int(s[i])] = 1;
			else freq[int(s[i])]++;
		}
		V<mypii> a;
		mypii p;
		for (auto it = freq.begin(); it != freq.end(); it++) { 
			p.x = it->second;
			p.y = it->first;
			a.pb(p);
		}
		sort(a.begin(), a.end());
		f(i, 0, a.size(), 1) cout << a[i].y << " " << a[i].x << nl;
	}
	return 0;
}
