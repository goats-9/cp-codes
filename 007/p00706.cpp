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

int main() {
	int s;
	string n;
	while (cin >> s >> n && s) { 
		string hl(s, '-');
		hl = ' ' + hl + ' ';
		string vl1 = "", vl2 = "", h1 = "", h2 = "", h3 = "";
		f(i, 0, n.size(), 1) { 
			if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '7') vl1 += string(s + 1, ' ') + '|';
			else if (n[i] == '5' || n[i] == '6') vl1 += '|' + string(s + 1, ' ');
			else vl1 += '|' + string(s, ' ') + '|';
			if (i + 1 != (int)n.size()) vl1 += ' ';
		}
		f(i, 0, n.size(), 1) { 
			if (n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '7' || n[i] == '9') vl2 += string(s + 1, ' ') + '|';
			else if (n[i] == '2') vl2 += '|' + string(s + 1, ' ');
			else vl2 += '|' + string(s, ' ') + '|';
			if (i + 1 != (int)n.size()) vl2 += ' ';
		}
		f(i, 0, n.size(), 1) { 
			if (n[i] == '1' || n[i] == '4') h1 += string(s + 2, ' ');
			else h1 += hl;
			if (i + 1 != (int)n.size()) h1 += ' ';
		}
		f(i, 0, n.size(), 1) { 
			if (n[i] == '1' || n[i] == '7' || n[i] == '0') h2 += string(s + 2, ' ');
			else h2 += hl;
			if (i + 1 != (int)n.size()) h2 += ' ';
		}
		f(i, 0, n.size(), 1) { 
			if (n[i] == '1' || n[i] == '4' || n[i] == '7') h3 += string(s + 2, ' ');
			else h3 += hl;
			if (i + 1 != (int)n.size()) h3 += ' ';
		}
		cout << h1 << "\n";
		f(i, 0, s, 1) cout << vl1 << "\n";
		cout << h2 << "\n";
		f(i, 0, s, 1) cout << vl2 << "\n";
		cout << h3 << "\n";
		cout << "\n";
	}
	return 0;
}
