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

bool allzero(vi &a, int n) { 
	f(i, 0, n, 1) if (a[i] != 0) return false;
	return true;
}

bool allnon(vi &a, int n) { 
	f(i, 0, n, 1) if (a[i] == 0) return false;
	return true;
}

int seg(vi &a, int n) { 
	int i = 0, ctr = 0;
	while (i < n) { 
		int k = 0;
		while (i + k < n && a[i + k] > 0) ++k;
		if (k != 0) ++ctr;
		i += max(k, 1);
	}
	return ctr;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n;
		cin >> n;
		vi a(n);
		f(i, 0, n, 1) cin >> a[i];
		int y = seg(a, n);
		if (allzero(a, n)) cout << "0\n";
		else if (allnon(a, n)) cout << "1\n";
		else cout << min(y, 2) << "\n";
	}
	return 0;
}
