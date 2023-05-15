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

int buckets[10010];

int main() {
	int n, q, x, tc = 0;
	while (cin >> n >> q && n) { 
		++tc;
		reset(buckets, 0);
		f(i, 0, n, 1) { 
			cin >> x;
			buckets[x]++;
		}
		vi a(n);
		int ctr = 0;
		f(i, 0, n, 1) { 
			while (!buckets[ctr]) ++ctr;
			a[i] = ctr;
			buckets[ctr]--;
		}
		cout << "CASE# " << tc << ":\n"; 
		f(i, 0, q, 1) { 
			cin >> x;
			int l = lower_bound(a.begin(), a.end(), x) - a.begin();
			if (a[l] == x) cout << x << " found at " << l + 1 << "\n";
			else cout << x << " not found\n";
		}
	}
	return 0;
}
