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
	int n;
	cin >> n;
	priority_queue<int> pq;
	f(i, 0, n, 1) pq.push(-i);
	while (!pq.empty()) { 
		int u = pq.top(); pq.pop();
		pq.push(u - n);
		u = pq.top(); pq.pop();
		cout << abs(u)%n + 1 << " ";
	}
	cout << nl;
	return 0;
}
