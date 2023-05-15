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

string s;
vector<string> sub;

bool findSub(string s, int idx, string sb) { 
	int n = s.size(), m = sb.size();
	if (idx + m > n) return false;
	f(i, 0, m, 1) if (s[idx + i] != sb[i]) return false;
	return true;
}

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> s >> n;
		int sz = s.size();
		sub.assign(n, "");
		f(i, 0, n, 1) cin >> sub[i];
		int r = -1, ir;
		f(i, 0, n, 1) { 
			int m = sub[i].size();
			if (findSub(s, 0, sub[i])) if (r < m) r = m, ir = i;
		}
		vector<pii> ans;
		if (r == -1) {cout << "-1\n"; continue;}
		else ans.pb(make_pair(1, ir + 1));
		while (r < sz) {
			int tmpr = 0, ir = 0, idx = 0;
			f(i, 0, r + 1, 1) { 
				f(j, 0, n, 1) { 
					int m = sub[j].size();
					if (findSub(s, i, sub[j])) if (tmpr < i + m) tmpr = i + m, idx = i, ir = j;
				}
			}
			if (tmpr > r) { 
				r = tmpr;
				ans.pb(make_pair(idx + 1, ir + 1));
			}
			else break;
		}
		if (r != sz) cout << "-1\n";
		else { 
			int sz = ans.size();
			cout << sz << "\n";
			f(i, 0, sz, 1) cout << ans[i].second << " " << ans[i].first << "\n";
		}
	}
	return 0;
}
