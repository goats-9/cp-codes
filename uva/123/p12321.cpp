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
#define MOD (int)1e9 + 7

int main() {
	int len, g, x, r;
    while (cin >> len >> g && len) { 
		vector<pii> st(g);
		f(i, 0, g, 1) { 
			cin >> x >> r;
			st[i] = make_pair(max(0, x - r), min(len, x + r));
		}
		sort(st.begin(), st.end(), [](pii a, pii b) { 
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
		});
		if (st[0].first) {cout << "-1\n"; continue;}
		int rb = st[0].second, fl = 1, ctr = 1, i = 1;
		while (i < g) { 
			if (st[i].first - rb > 0) {fl = 0; break;}
			else { 
				int rt = 0;
				while (i < g && st[i].first - rb <= 0) {
					if (st[i].second > rt) rt = st[i].second;
					i++;
				}
				if (rt > rb) rb = rt, ++ctr;
			}
		}
		if (rb < len) fl = 0;
		if (fl) cout << g-ctr << "\n";
		else cout << "-1\n";
	}
	return 0;
}
