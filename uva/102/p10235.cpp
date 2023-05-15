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
	f(i, 2, floor(sqrt(n)) + 1, 1) if (!(n%i)) return false;
	return true;
}

int rev(int n) { 
	int r = 0;
	while (n) { 
		r = 10*r + (n%10);
		n/=10;
	}
	return r;
}

int main() {
	int n;
	while (cin >> n) { 
		if (!isPrime(n)) cout << n << " is not prime.\n";
		else if (rev(n) == n || !isPrime(rev(n))) cout << n << " is prime.\n";
		else cout << n << " is emirp.\n";
	}
	return 0;
}
