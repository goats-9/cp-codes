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
	vi tri;
	int n, i = 1, t = 1;
	while (t < 10000000) { 
		tri.pb(t);
		++i;
		t += i;
	}
	while (cin >> n) { 
		int idx = lower_bound(tri.begin(), tri.end(), n) - tri.begin();
		int sm = idx + 2;
		int num = n - tri[idx - 1];
		int dnm = sm - num;
		cout << "TERM " << n << " IS ";
		if (sm%2) cout << num << "/" << dnm;
		else cout << dnm << "/" << num;
		cout << "\n";
	}
}
