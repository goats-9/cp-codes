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
	int m, q;
	cin >> m >> q;
	vector<string> a(m), b(q);
	f(i, 0, m, 1) cin >> a[i];
	f(i, 0, q, 1) cin >> b[i];
	f(i, 0, q, 1) { 
		int hd = INT_MAX, idx = 0, val;
		f(j, 0, m, 1) { 
			int sa = a[j].size(), sb = b[i].size();
			if (sa < sb) continue;
			f(k, 0, sa - sb + 1, 1) { 
				val = 0;
				f(l, 0, sb, 1) if (a[j][l + k] != b[i][l]) ++val;
				if (hd > val) hd = val, idx = j;
			}
		}
		cout << idx + 1 << "\n";
	}
	return 0;
}
