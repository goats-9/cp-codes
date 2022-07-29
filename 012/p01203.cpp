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
#define MOD (int)1e9 + 7

struct myii { 
	int query, time;
	bool operator < (const myii &a) const { 
		if (time != a.time) return time > a.time;
		else return query > a.query;
	}
};

int main() {
	string s;
	map<int, int> mp;
	priority_queue<myii> q;
	int n, x, y;
	while (cin >> s && s == "Register") { 
		cin >> x >> y;
		mp[x] = y;
		myii pr = {.query = x, .time = y};
		q.push(pr);
	}
	cin >> n;
	f(i, 0, n, 1) { 
		int rt = q.top().time;
		int rq = q.top().query;
		q.pop();
		myii pr = {.query = rq, .time = rt + mp[rq]};
		q.push(pr);
		cout << rq << "\n";
	}
	return 0;
}
