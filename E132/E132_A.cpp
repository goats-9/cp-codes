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

int d[3], o[3], x;

int solve() { 
	while (!o[x - 1]) { 
		o[x - 1] = 1;
		x = d[x - 1];
	}
	if (o[0] && o[1] && o[2]) return 1;
	else return 0;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		reset(o, 0), reset(d, 0);
		cin >> x >> d[0] >> d[1] >> d[2];
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
