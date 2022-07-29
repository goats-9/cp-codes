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

class SegTree { 
	vi A, st;
	int n;
	int left(int p) { return (p << 1); }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) { 
		if (L == R) st[p] = A[L];
		else { 
			int m = (L + R)/2;
			build(left(p), L, m);
			build(right(p), m+1, R);
			st[p] = min(st[left(p)], st[right(p)]);
		}
	}

	int rmq(int p, int L, int R, int i, int j) { 
		if (i > R || L > j) return -1;
		if (L >= i && j >= R) return st[p];
		int m = (L+R)/2;
		int p1 = rmq(left(p), L, m, i, j);
		int p2 = rmq(right(p), m+1, R, i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return min(p1, p2);
	}

	void update(int p, int L, int R, int i, int val) { 
		if (i < L || i > R) return;
		if (L == R) st[p] = val;
		else { 
			int m = (L+R)/2;
			update(left(p), L, m, i, val);
			update(right(p), m+1, R, i, val);
			st[p] = min(st[left(p)], st[right(p)]);
		}
	}
public:
	SegTree (vi B) { 
		A = B;
		n = B.size();
		st.assign(4*n, 0);
		build(1, 0, n - 1);
	}
	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
	void update(int i, int val) { update(1, 0, n - 1, i, val); }
};

bool isDigit(char x) { return '0' <= x && x <= '9'; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vi a(n);
	f(i, 0, n, 1) cin >> a[i];
	SegTree tree(a);
	string s;
	f(i, 0, m, 1) { 
		cin >> s;
		int sz = s.size();
		if (s[0] == 'q') { 
			int x = 0, y = 0, i = 6;
			while (i < sz && isDigit(s[i])) x = 10*x + (s[i++] - '0');
			i++;
			while (i < sz && isDigit(s[i])) y = 10*y + (s[i++] - '0');
			cout << tree.rmq(x - 1, y - 1) << "\n";
		} else { 
			int k, x, i = 6;
			vi shift, vals;
			while (i < sz) { 
				x = 0;
				while (isDigit(s[i])) x = 10*x + (s[i++] - '0');
				++i;
				shift.pb(x - 1);
				vals.pb(a[x - 1]);
			}
			k = shift.size();
			f(i, 0, k, 1) { 
				tree.update(shift[i], vals[(i+1)%k]);
				a[shift[i]] = vals[(i+1)%k];
			}
		}
	}
	return 0;
}
