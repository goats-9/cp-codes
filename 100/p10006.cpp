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

ll rem(int a, int e, int n) { 
	if (e == 0) return 1;
	else { 
		ll x = rem(a, e/2, n)%n;
		return ((e%2 ? a%n : 1)*x*x)%n;
	}
}

bool isPrime(int n) { 
	f(i, 2, sqrt(n) + 1, 1) if (!(n%i)) return false;
	return true;
}

bool carmichael(int n) { 
	if (isPrime(n)) return false;
	f(i, 2, n, 1) if (n%i && rem(i, n, n) != i) return false;
	return true;
}

int main() {
	int n;
	vi cm(65000);
	f(i, 3, 65000, 1) if (carmichael(i)) cm[i] = 1;
    while (cin >> n && n) {
		if (cm[n]) cout << "The number " << n << " is a Carmichael number.\n";
		else cout << n << " is normal.\n";
	}
	return 0;
}
