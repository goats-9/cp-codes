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

bool div(string &s) { 
	int n = s.size(), r = 0;
	f(i, 0, n, 1) { 
		int D = r*10 + (s[i] - '0');
		r = D%17;
	}
	return !r;
}

int main() {
	string s;
    while (cin >> s && s != "0") { 
		if (div(s)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
