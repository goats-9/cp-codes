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

int ds(int n) { 
	int ans = 0;
	while (n) { 
		ans += n%10;
		n/=10;
	}
	return ans;
}

bool isPrime(int n) { 
	f(i, 2, sqrt(n) + 1, 1) if (!(n%i)) return false;
	return true;
}

int main() {
	vi p;
	f(i, 2, 1000001, 1) if (isPrime(i) && isPrime(ds(i))) p.pb(i);
	int t1, t2, t;
    scanf("%d", &t);
    while (t--) { 
		scanf("%d %d", &t1, &t2);
		printf("%d\n", int(upper_bound(p.begin(), p.end(), t2) - lower_bound(p.begin(), p.end(), t1)));
	}
	return 0;
}
