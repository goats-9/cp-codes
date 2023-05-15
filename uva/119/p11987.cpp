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
#define N 200001

int p[N], elem[N], id[N];
ll sum[N];

void init(int n) { 	f(i, 0, n, 1) p[i] = i, sum[i] = i, elem[i] = 1, id[i] = i; }

int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }

void join(int x, int y) { 
	if (x == y) return;
	sum[y] += sum[x], elem[y] += elem[x];
	sum[x] = elem[x] = 0;
	p[x] = y;
}

int main() {
	int n, m, q, x, y;
	while (cin >> n >> m) { 
		init(n + m);
		f(i, 0, m, 1) { 
			cin >> q >> x;
			if (q == 1) { 
				cin >> y;
				join(root(id[x]), root(id[y]));
			} else if (q == 2) { 
				cin >> y;
				int r1 = root(id[x]), r2 = root(id[y]);
				if (r1 != r2) { 
					sum[r1] -= x, elem[r1]--;
					id[x] = ++n;
					sum[id[x]] = x;
					join(root(id[x]), root(id[y]));
				}
			} else cout << elem[root(id[x])] << " " << sum[root(id[x])] << "\n";
		}
	}
	return 0;
}
