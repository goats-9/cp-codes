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
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		set<int> s (a.begin(), a.end());
		int k = s.size();
		if ((n % 2) ^ (k % 2)) cout << k - 1 << "\n";
		else cout << k << "\n";
	}
	return 0;
}
