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

int n, a, b, c;
vi st;
vector<pii> t;

int numAwake() { 
	int ctr = 0;
	f(i, 0, n, 1) if (st[i] <= t[i].first) ++ctr;
	return ctr;
}

int main() {
	int tc = 0;
	while (cin >> n && n) { 
		tc++;
		st.assign(n, 0);
		t.assign(n, {0, 0});
		f(i, 0, n, 1) { 
			cin >> t[i].first >> t[i].second >> st[i];
		}
		int ans = 1, x;
		while ((x = numAwake()) != n && ans < 1000000) { 
			f(i, 0, n, 1) { 
				if (st[i] == t[i].first) { 
					if (2*x >= n) st[i] = 1;
					else st[i]++;
				} else if (st[i] == t[i].first + t[i].second) st[i] = 1;
				else st[i]++;
			}
			++ans;
		}
		cout << "Case " << tc << ": ";
		if (ans == 1000000) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}
