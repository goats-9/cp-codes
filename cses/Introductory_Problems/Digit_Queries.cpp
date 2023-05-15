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
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

ll pow(ll a, ll b) { 
	if (b == 0LL) return 1;
	ll x = pow(a, b/2);
	x *= x;
	return (b%2) ? a*x : x;
}

int main() {
	int q;
	ll k;
    scanf("%d", &q);
    while (q--) { 
		cin >> k;
		ll i = 1, j = 9;
		while (k > i*j) { 
			k -= i*j;
			++i, j *= 10;
		}
		ll num = pow(10LL, i - 1) + (k - 1)/i;
		string s = "";
		while (num) { 
			s = char(num%10 + '0') + s;
			num /= 10;
		}
		cout << s[(k - 1)%i] << nl;
	}
	return 0;
}
