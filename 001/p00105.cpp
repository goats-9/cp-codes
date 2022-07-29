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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7

int hmap[10010];

int main() {
	int x, y, z;
	vi l, h, r;
    while (cin >> x >> y >> z) { 
		l.pb(x);
		h.pb(y);
		r.pb(z);
	}
	f(i, 0, h.size(), 1) f(j, l[i], r[i], 1) hmap[j] = max(hmap[j], h[i]);
	cout << l[0] << " ";
	int i = l[0], hm = hmap[i];
	while (i <= r[max_element(r.begin(), r.end()) - r.begin()]) { 
		if (hm != hmap[i]) { 
			cout << hm << " " << i << " ";
			hm = hmap[i];
		}
		++i;
	}
	cout << "0\n";

}
