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

V<pair<pii, int>> ele(1010);
vi p;

void disp(int i) { 
	if (p[i] == -1) {cout << i << nl; return;}
	disp(p[i]);
	cout << i << nl;
}

int main() {
	int x, y, ctr = 0, sz, k = 0, l_g = 0;
	while (cin >> x >> y) {ele[ctr] = mp(pii(x, y), ctr + 1); ++ctr;}
	sort(ele.begin(), ele.end(), [](pair<pii, int> a, pair<pii, int> b) { return a.first.second > b.first.second; });
	sz = ele.size();
	vi L(sz, 0), L_id(sz, 0);
	p.assign(sz, -1);
	f(i, 0, sz, 1) { 
		int pos = lower_bound(L.begin(), L.begin() + k, ele[i].first.first) - L.begin();
		L[pos] = ele[i].first.first;
		L_id[pos] = ele[i].second;
		p[ele[i].second] = pos ? L_id[pos - 1] : -1; 
		if (pos == k) { ++k; l_g = ele[i].second; }
	}
	cout << k << nl;
	disp(l_g);
	return 0;
}
