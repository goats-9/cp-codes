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

int solve(string &s) { 
	int n = s.size();
	f(i, 1, n/2 + 1, 1) { 
		if (!(n%i)) { 
			int fl = 1;
			f(j, 0, i, 1) { 
				char k = s[j];
				int idx = j;
				while (idx < n) { 
					if (s[idx] != k) {fl = 0; break;}
					else idx += i;
				}
				if (!fl) break;
			}
			if (fl) return i;
		}
	}
	return n;
}

int main() {
	int t;
	string s;
    scanf("%d", &t);
    f(k, 0, t, 1) {
		if (k) cout << nl;
		cin >> s;
		cout << solve(s) << nl;
	}
	return 0;
}
