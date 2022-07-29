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
	int n, x, y;
	while (cin >> n && n) { 
		vi a(n);
		ll cost = 0LL;
		f(i, 0, n, 1) cin >> a[i];
		priority_queue<int, vi, greater<int>> q(a.begin(), a.end());
		while (q.size() > 1) { 
			x = q.top();
			q.pop();
			y = q.top();
			q.pop();
			cost += (x + y);
			q.push(x + y);
		}
		cout << cost << "\n";
	}
	return 0;
}
