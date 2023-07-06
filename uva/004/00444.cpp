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
	string s;
	while (getline(cin, s)) {
		if (s.empty()) {cout << nl; continue;}
		if (isdigit(s[0])) {
			reverse(all(s));
			int i = 0, sz = s.size();
			while (i < sz) {
				int d = 0;
				if (s[i] == '1') {
					d = atoi(s.substr(i,3).c_str());
					cout << char(d);
					i += 3;
				} else {
					d = atoi(s.substr(i,2).c_str());
					cout << char(d);
					i += 2;
				}
			}
			cout << nl;
		} else {
			stringstream ss;
			for (char ch : s) ss << (int)ch;
			string t = ss.str();
			reverse(all(t));
			cout << t << nl;
		}
	}
	return 0;
}
