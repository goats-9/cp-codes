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


string add(string a, string b) { 
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
	return a;
}

vector<string> fib(5005);

int main() {
	fib[0] = "0";
	fib[1] = "1";
	f(i, 2, 5001, 1) fib[i] = add(fib[i - 1], fib[i - 2]);
	int n;
	while (cin >> n) cout << "The Fibonacci number for " << n << " is " << fib[n] << "\n";
	return 0;
}
