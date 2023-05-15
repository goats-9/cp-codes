#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7
#define LSOne(s) (s & (-s))

class FenTree { 
private: 
	vi ft; int n;
	
	int query(int i) { 
		int ret = 0;
		for (; i > 0; i -= LSOne(i)) ret += ft[i];
		return ret;
	}

public:
	FenTree (int sz) {n = sz; ft.assign(n + 1, 0);}

	void update(int idx, int val) { for (;idx <= n; idx += LSOne(idx)) ft[idx]++; }

	void refresh() { ft.assign(n + 1, 0); }

	int query(int i, int j) { return query(j) - query(i - 1);}
};

typedef struct { int l, r, t; } rng;

int main() {
	int n;
	scanf("%d", &n);
	V<rng> a(n);
	mii ft_id;
	int uid = 1;
	vi p(n), q(n);
	f(i, 0, n, 1) {
		scanf("%d %d", &a[i].l, &a[i].r);
		a[i].t = i;
		ft_id[a[i].l] = ft_id[a[i].r] = 1;
	}
	for (auto &x : ft_id) ft_id[x.first] = uid++;
	FenTree tr(ft_id.size());
	sort(all(a), [](rng a, rng b) { 
		if (a.l == b.l) return a.r > b.r;
		else return a.l < b.l;
	});
	f(i, 0, n, 1) { 
		p[a[i].t] = i - tr.query(1, ft_id[a[i].r] - 1);
		tr.update(ft_id[a[i].r], 1);
	}
	reverse(all(a));
	tr.refresh();
	f(i, 0, n, 1) { 
		q[a[i].t] = tr.query(1, ft_id[a[i].r]);
		tr.update(ft_id[a[i].r], 1);
	}
	f(i, 0, n, 1) cout << q[i] << " ";
	cout << nl;
	f(i, 0, n, 1) cout << p[i] << " ";
	cout << nl;
	return 0;
}
