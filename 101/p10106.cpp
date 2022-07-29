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

int digit(char x) { return x - '0'; }

void add(string &a, string &b) { 
	int sa = a.size(), sb = b.size();
	if (sa < sb || (sa == sb && a < b)) swap(a, b);
	sa = a.size(), sb = b.size();
	int s, c = 0;
	f(i, 0, sa, 1) { 
		if (sb - i - 1 >= 0) { 
			s = c + digit(a[sa - 1 - i]) + digit(b[sb - i - 1]);
			c = s/10;
			a[sa - 1 - i] = (s%10) + '0';
		} else { 
			s = c + digit(a[sa - 1 - i]);
			c = s/10;
			a[sa - 1 - i] = (s%10) + '0';		
		}
	}
	if (c > 0) a = char(c + '0') + a;
}

void disp(string &a) { 
	int n = a.size(), fl = 0;
	f(i, 0, n, 1) { 
		if (!fl && a[i] != '0') fl = 1;
		if (fl) cout << a[i];
	}
	if (!fl) cout << "0\n";
	else cout << "\n";
}


string mul(string &a, string &b) { 
	int sa = a.size(), sb = b.size();
	if (sa < sb || (sa == sb && a < b)) swap(a, b);
	sa = a.size(), sb = b.size();
	string p, ans = "";
	int pr, c, d;
	f(i, 0, sb, 1) { 
		d = digit(b[i]);
		c = 0;
		p = "";
		f(j, 0, sa, 1) { 
			pr = c + d*(digit(a[sa - 1 - j]));
			p = char(pr%10 + '0') + p;
			c = pr/10;
		}
		if (c) p = char(c + '0') + p; 
		f(j, i + 1, sb, 1) p += "0";
		if (ans == "") ans = p;
		else add(ans, p);
	}
	return ans;
}

int main() {
	string a, b;
	while (cin >> a >> b) {
		string ds = mul(a, b);
		disp(ds);
	}
	return 0;
}
