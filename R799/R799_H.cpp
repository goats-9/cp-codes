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

int main() {
	int t;
    scanf("%d", &t);
    while (t--) {
		int n;
		cin >> n;
		vi a(n), c(n);
		f(i, 0, n, 1) cin >> a[i];
		vi b(a);
		sort(a.begin(), a.end());
		int m = 0, m_elem = 0, i = 0;
		while (i < n) {
			int k = 0;
			while (i + k < n && a[i] == a[i + k]) ++k;
			if (k > m) {
				cout << k << " " << m << "\n";
				m = k, m_elem = a[i];
			}
			i += k;
		}
		cout << m << " " <<  m_elem << "\n";
		f(i, 0, n, 1) c[i] = (b[i] == m_elem) ? 1 : -1;
		int s = 0, l = 0, r = 0, ms = 0;
		f(i, 0, n, 1) {
			s += c[i];
			if (s < 0) l = i + 1, s = 0, r = i + 1;
			else if (s > ms) r = i, ms = s;
		}
		cout << m_elem << " " << l + 1 << " " << r + 1 << "\n";
	}
	return 0;
}
