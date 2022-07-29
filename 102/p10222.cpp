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

string l = "qwertyuiop[asdfghjklzxcvbnm,";
string r = "ertyuiop[]\\dfghjkl;\'cvbnm,./";
map<char, char> m;

int main() {
	f(i, 0, l.size(), 1) m[r[i]] = l[i];
	string s;
    while (getline(cin, s)) { 
		f(i, 0, s.size(), 1) { 
			if (m.find(s[i]) == m.end()) cout << s[i];
			else cout << m[s[i]];
		}
		cout << "\n";
	}
	return 0;
}
