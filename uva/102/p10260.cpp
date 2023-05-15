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

vi sd = {-1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5, 5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2};

int main() {
	string s;
	while (cin >> s) { 
		int d = -1;
		f(i, 0, s.size(), 1) { 
			if (sd[s[i] - 'A'] != -1 && sd[s[i] - 'A'] != d) { 
				cout << sd[s[i] - 'A'];
			}
			d = sd[s[i] - 'A'];
		}
		cout << nl;
	}
	return 0;
}
