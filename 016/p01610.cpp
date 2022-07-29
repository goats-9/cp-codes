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

int main() {
	int n;
    while (cin >> n && n) { 
		vector<string> name(n);
		f(i, 0, n, 1) cin >> name[i];
		sort(name.begin(), name.end());
		string a = name[n/2 - 1];
		string b = name[n/2];
		string ans = "";
		int sa = a.size(), sb = b.size(), sz = min(sa, sb);
		f(i, 0, sz, 1) { 
			if (a[i] < b[i] && i != sa - 1) {ans += char(a[i] + 1); break;}
			else ans += a[i];
		}
		if (ans == b) { 
			ans[sb - 1]--;
			if (sa > sb) {
				f(i, sb, sa, 1) { 
					if (a[i] != 'Z' && i != sa - 1) {ans += char(a[i] + 1); break;}
					ans += a[i];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
