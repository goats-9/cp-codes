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

struct myii { 
	int val;
	int pos;
	bool operator < (const myii &b) const { return val > b.val; }
};

int main() {
	int k;
	while (cin >> k) { 
		vi a(k), b(k);
		f(i, 0, k, 1) cin >> a[i];
		sort(a.begin(), a.end());
		f(i, 1, k, 1) { 
			f(j, 0, k, 1) cin >> b[j];
			sort(b.begin(), b.end());
			priority_queue<myii> q;
			myii elem;
			f(j, 0, k, 1) {
				elem.val = a[j] + b[0];
				elem.pos = 0;
				q.push(elem);
			}
			f(j, 0, k, 1) { 
				elem = q.top();
				q.pop();
				a[j] = elem.val;
				elem.val += b[elem.pos + 1] - b[elem.pos];
				elem.pos++;
				if (elem.pos < k) q.push(elem);
			}
		}
		f(i, 0, k, 1) { 
			cout << a[i];
			if (i == k - 1) cout << "\n";
			else cout << " ";
		}
	}
	return 0;
}
