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

vi a, p, l, l_id;
int n, sz, k, lis_end;

void print_LIS(int i) { 
	if (p[i] == -1) { cout << a[i] << "\n"; return; }
	print_LIS(p[i]);
	cout << a[i] << "\n"; 
}

int main() {
	lis_end = 0, k = 0;
	while (cin >> n) a.pb(n);
	sz = a.size();
	l.assign(sz, 0);
	l_id = l;
	p.assign(sz, -1);
	f(i, 0, sz, 1) { 
		int pos = lower_bound(l.begin(), l.begin() + k, a[i]) - l.begin();
		l[pos] = a[i]; l_id[pos] = i;
		p[i] = pos ? l_id[pos - 1] : -1;
		if (k == pos) { 
			k = pos + 1;
			lis_end = i;
		}
	}
	cout << k << "\n-\n";
	print_LIS(lis_end);
	return 0;
}
