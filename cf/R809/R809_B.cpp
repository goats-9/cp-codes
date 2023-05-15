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
		vi a(n), p(n + 1), b(n + 1), v(n + 1);
		f(i, 0, n, 1) { 
			cin >> a[i];
			if (!b[a[i]]) {b[a[i]] = 1; p[a[i]] = i; ++v[a[i]];}
			else if((i - p[a[i]])%2) {p[a[i]] = i; ++v[a[i]];}
		}
		f(i, 0, n, 1) { 
			cout << v[i + 1] << " "; 
		}
		cout << "\n";
	}
	return 0;
}
