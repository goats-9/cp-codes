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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

bool cmp(pii a, pii b) { 
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
		cin >> n;
		V<pii> jobs(n);
		f(i, 0, n, 1) cin >> jobs[i].first >> jobs[i].second;
		sort(jobs.begin(), jobs.end(), cmp);
		priority_queue<int> pq;
		int tm = 0;
		f(i, 0, n, 1) { 
			pq.push(jobs[i].first);
			tm += jobs[i].first;
			if (tm > jobs[i].second) tm -= pq.top(), pq.pop();
		}
		cout << pq.size() << nl;
		if (t) cout << nl;
	}
	return 0;
}
