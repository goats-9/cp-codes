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

string rev(string &s) { 
	string p = "";
	f(i, 0, s.size(), 1) p = s[i] + p;
	return p;
}

int main() {
	string s;
	while (getline(cin, s) && s != "DONE") {
		string a = "";
		f(i, 0, s.size(), 1) if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) a += tolower(s[i]);
		if (rev(a) == a) cout << "You won't be eaten!";
		else cout << "Uh oh..";
		cout << nl;
	}
	return 0;
}
