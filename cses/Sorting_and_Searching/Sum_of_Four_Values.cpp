#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

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
	int n, x;
	cin >> n >> x;
	if (n < 4) { 
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vll a(n);
	f(i, 0, n, 1) cin >> a[i];
	gp_hash_table<ll, pii> g({},{},{},{},{1<<20});
	f(i, 0, n, 1) f(j, i + 1, n, 1) g[a[i] + a[j]] = pii(i, j);
	f(i, 0, n, 1) { 
		f(j, i + 1, n, 1) { 
			auto it = g.find(x - a[i] - a[j]);
			if (it != end(g)) { 
				int p = it->second.first, q = it->second.second;
				if (i != p && i != q && j != p && j != q) {cout << i + 1 << " " << j + 1 << " " << p + 1 << " " << q + 1 << nl; return 0;}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
