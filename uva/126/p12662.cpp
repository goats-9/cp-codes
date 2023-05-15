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
	int n, q, t;
	cin >> n;
	vector<string> st(n);
	vi st_idx;
	f(i, 0, n, 1) { 
		cin >> st[i];
		if (st[i] != "?") st_idx.pb(i);
	}
	cin >> t;
    while (t--) { 
		cin >> q;
		int idx1 = lower_bound(st_idx.begin(), st_idx.end(), q - 1) - st_idx.begin(), idx2 = idx1 - 1;
		if (idx1 == (int)st_idx.size()) { 
			f(i, 0, q - st_idx[idx2] - 1, 1) cout << "right of ";
			cout << st[st_idx[idx2]] << "\n";
		} else if (idx1 == 0 && q - 1 < st_idx[0]) { 
			f(i, 0, st_idx[0] + 1 - q, 1) cout << "left of ";
			cout << st[st_idx[0]] << "\n";
		} else if (q - 1 == st_idx[idx1]) cout << st[st_idx[idx1]] << "\n";
		else { 
			int x = st_idx[idx1] + 1 - q, y = q - 1 - st_idx[idx2];
			if (x > y) { 
				f(i, 0, y, 1) cout << "right of ";
				cout << st[st_idx[idx2]] << "\n";
			} else if (x == y) cout << "middle of " << st[st_idx[idx2]] << " and " << st[st_idx[idx1]] << "\n";
			else { 
				f(i, 0, x, 1) cout << "left of ";
				cout << st[st_idx[idx1]] << "\n";
			}
		}
	}
	return 0;
}
