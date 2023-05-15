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
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int x, n, t;
	cin >> x >> n;
	multiset<int> len;
	set<int> jn;
	f(i, 0, n, 1) { 
		cin >> t;
		if (i == 0) { 
			cout << max(t, x - t) << " ";
			jn.insert(t); len.insert(t); len.insert(x - t);
		} else {
			int a = 0, b = 0;
			auto it = jn.upper_bound(t);
			if (it == jn.end()) a = x, b = *jn.rbegin();
			else if (it == jn.begin()) a = *it, b = 0;
			else a = *it, b = *(--it);
			jn.insert(t);
			len.erase(len.find(a - b));
			len.insert(a - t);
			len.insert(t - b);
			cout << *len.rbegin() << " ";
		}
	}
	cout << nl;
	return 0;
}
