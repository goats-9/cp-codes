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

int n;

void solve(string &s) { 
	vi bal(n);
	if (s[0] == ')') bal[0] = 1;
	else if (s[0] == '(') bal[0] = -1;
	vi qn;
	f(i, 1, n, 1) {
		s[i] = s[i - 1];
		if (s[i] = '(') ++s[i];
		else if (s[i] == ')') --s[i];
	}
}

int main() {
	int t;
	string s;
    cin >> t;
    while (t--) { 
		cin >> s;
		n = s.size();
		if (s == "??" || solve(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
