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

bool isPrime(int n) { 
	f(i, 2, int(sqrt(n)) + 1, 1) if (!(n%i)) return false;
	return true;
}

int val(char x) { 
	if (islower(x)) return x - 'a' + 1;
	else return x - 'A' + 27;
}

int main() {
	string s;
	while (cin >> s) { 
		int n = 0;
		f(i, 0, s.size(), 1) n += val(s[i]);
		if (isPrime(n)) cout << "It is a prime word.\n";
		else cout << "It is not a prime word.\n";
	}
	return 0;
}
