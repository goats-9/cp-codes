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
#define N (int)2e5 + 1

int main() {
	int n, x, y; cin >> n;
	V<P<pii, int>> a;
	priority_queue<int> pq;
	vi occ(n);
	f(i, 1, N + 1, 1) pq.push(-i);
	f(i, 0, n, 1) { 
		cin >> x >> y;
		a.pb(mp(pii(x, 0), i)), a.pb(mp(pii(y, 1), i));
	}
	sort(all(a));
	f(i, 0, a.size(), 1) { 
		if (a[i].first.second) pq.push(-occ[a[i].second]);
		else { 
			occ[a[i].second] = -pq.top();
			pq.pop();
		}
	}
	int mx = 0;
	f(i, 0, n, 1) mx = max(mx, occ[i]);
	cout << mx << nl;
	f(i, 0, n, 1) cout << occ[i] << " ";
	cout << nl;
	return 0;
}
