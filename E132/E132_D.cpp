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
#define LSOne(s) (s & (-s))

class SegTree { 
	vi st;
	vi a;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int l, int r) { 
		if (l == r) st[p] = l;
		else { 
			build(left(p), l, (l + r)/2);
			build(right(p), (l + r)/2 +1, r);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (a[p1] <= a[p2]) ? p2 : p1;
		}
	}

	int rmq(int p, int l, int r, int i, int j) { 
		if (i > r || j < l) return -1;
		if (l >= i && r <= j) return st[p];
		int p1 = rmq(left(p), l, (l + r)/2, i, j);
		int p2 = rmq(right(p), (l + r)/2 + 1, r, i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return (a[p1] <= a[p2]) ? p2 : p1;
	}

public:
	SegTree(vi &b) {
		a = b;
		n = a.size();
		st.assign(4*n, 0);
		build(1, 0, n - 1);
	}

	int rmq(int i, int j) {return rmq(1, 0, n - 1, i, j);}
};

int main() {
	int n, m, q, xs, ys, xf, yf, k;
	cin >> n >> m;
	vi a(m);
	f(i, 0, m, 1) cin >> a[i];
	SegTree tree(a);
	cin >> q;
	f(i, 0, q, 1) { 
		cin >> xs >> ys >> xf >> yf >> k;
		if ((xf - xs)%k || (yf - ys)%k) cout << "NO\n";
		else if (a[ys - 1] >= n - xs || a[yf - 1] >= n - xf) cout << "NO\n";
		else { 
			int chk = xs - (xs/k)*k;
			int l = min(ys, yf), r = max(ys, yf);
			if (tree.rmq(l, r) >= n - chk) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}
