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
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353
#define N 2001

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) if (!(n%i)) return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	f(k,1,t+1,1) { 
		string s;
		cin >> s;
		vi a(200);
		for (char ch : s) ++a[(int)ch];
		string r = "";
		f(i,0,200,1) {
			int x = a[i];
			if (isPrime(x)) {
				r += char(i);
			}
		}
		cout << "Case " << k << ": ";
		if (r == "") cout << "empty\n";
		else cout << r << nl;
	}
	return 0;
}
