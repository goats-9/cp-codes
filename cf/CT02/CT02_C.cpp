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
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n, m;
		cin >> n >> m;
		vi a(m), b(m);
		f(i, 0, m, 1) cin >> a[i];
		sort(a.begin(), a.end());
		f(i, 0, m - 1, 1) b[i] = a[i + 1] - a[i] - 1;
		b[m - 1] = a[0] + n - a[m - 1] - 1;
		sort(b.rbegin(), b.rend());
		int ctr = 0;
		f(i, 0, m, 1) {
			if (b[ctr] > 1) b[ctr] = max(b[ctr] - 1, 0);
			++ctr;
			f(j, ctr, m, 1) { 
				if (b[j]) b[j] = max(b[j] - 4, 0); 
				else break;
			}
		}
		int sm = 0;
		f(i, 0, m, 1) {
			if (b[i]) sm += b[i];
			else break;
		}
		cout << n - sm << "\n";
	}
	return 0;
}
