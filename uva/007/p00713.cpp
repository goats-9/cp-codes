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

void rev(string &s) { 
	int n = s.size(), k = 0;
	reverse(s.begin(), s.end());
	while (k < n && s[k] == '0') ++k;
	if (k == n) s = "0";
	else s = s.substr(k, n - k);
}

void add(string &p, string &q) { 
	if (p.size() < q.size() || (p.size() == q.size() && p < q)) swap(p, q);
	int sp = p.size(), sq = q.size(), c = 0, sm;
	f(i, 0, sp, 1) { 
		if (sq - i - 1 >= 0) sm = q[sq - i - 1] + c + p[sp - i - 1] - 2*'0';
		else sm = c + p[sp - i - 1] - '0';
		c = sm/10;
		p[sp - i - 1] = char(sm%10 + '0');
	}
	if (c) p = char(c + '0') + p;
}

int main() {
	int t;
	string a, b;
    scanf("%d", &t);
    while (t--) { 
		cin >> a >> b;
		rev(a); rev(b); add(a, b); rev(a);
		cout << a << nl;
	}
	return 0;
}
