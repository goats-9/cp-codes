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

int freq[26];

void disp() { 
	string s = "", p = "", o = "";
	f(i, 0, 26, 1) { 
		if (freq[i] != 0) { 
			if (freq[i]%2) o.assign(freq[i], char('A' + i));
			else { 
				string x(freq[i]/2, char('A' + i));
				s += x;
				p = x + p;
			}
		}
	}
	cout << s + o + p << nl;
}

int main() {
	string s;
	cin >> s;
	int n = s.size(), oc = 0;
	reset(freq, 0);
	f(i, 0, n, 1) ++freq[s[i] - 'A'];
	f(i, 0, 26, 1) if(freq[i]%2) ++oc;
	if (n%2) { 
		if (oc == 1) disp();
		else cout << "NO SOLUTION\n";
	} else { 
		if (oc == 0) disp();
		else cout << "NO SOLUTION\n";
	}
	return 0;
}
