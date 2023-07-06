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

int main() {
	int t;
	cin >> t;
	cin.ignore(1);
	while (t--) { 
		string inp, s, s11 = "", s12 = "", s21 = "", s22 = "";
		getline(cin, inp);
		int l1 = -1, l2 = -1, r1 = -1, r2 = -1;
		l1 = inp.find('<');
		l2 = inp.find('<',l1+1);
		r1 = inp.find('>');
		r2 = inp.find('>',r1+1);
		s11 = inp.substr(l1+1,r1-l1-1);
		s12 = inp.substr(r1+1,l2-r1-1);
		s21 = inp.substr(l2+1,r2-l2-1);
		s22 = inp.substr(r2+1);
		cout << inp.substr(0,l1) + s11 + s12 + s21 + s22 << nl;
		getline(cin, inp);
		int n = inp.size();
		cout << inp.substr(0,n-3);
		cout << s21+s12 << s11+s22 << nl;
	}
	return 0;
}
