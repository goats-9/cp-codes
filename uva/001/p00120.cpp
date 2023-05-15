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

bool isdigit(char x) { return ((x >= '0') && (x <= '9')); }

void disp(vi &v) { 
	f(i, 0, v.size(), 1) { 
		cout << v[i];
		if (i == int(v.size()) - 1) cout << "\n";
		else cout << " ";
	}
}

int main() {
	string s;
	int d, n, i, k;
	while (getline(cin, s)) { 
		i = 0;
		n = s.size();
		vi swp, srt, p;
		while (i < n) { 
			if (isdigit(s[i])) { 
				k = 0, d = 0;
				while (isdigit(s[i + k])) d = 10*d + (s[i + k] - '0'), ++k;
				p.pb(d);
				i += k;
			} else ++i;
		}
		cout << s << "\n";
		srt = p;
		sort(srt.rbegin(), srt.rend());
		n = p.size();
		f(i, 0, n, 1) { 
			int idx = find(p.begin(), p.end(), srt[i]) - p.begin();
			if (idx < n - i - 1) { 
				if (idx > 0) {
					swp.pb(n - idx);
					reverse(p.begin(), p.begin() + idx + 1);
				}
				swp.pb(i + 1);
				reverse(p.begin(), p.end() - i);
			}
		}
		swp.pb(0);
		disp(swp);
	}
	return 0;
}
