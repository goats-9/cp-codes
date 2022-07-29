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

bool isnum(char x) { return ((x >= '0') && (x <= '9')); }

int main() {
	string s;
	int n;
	vector<string> list;
	while (getline(cin, s)) { 
		if (s == "0") break;
		n = s.size();
		string x = "";
		int i = 0;
		while (i < n) { 
			if (isnum(s[i])) { 
				int k = 0, l = 0;
				while (i + k < n && isnum(s[i + k])) {l = 10*l + (s[i + k] - '0'); ++k;}
				i += k;
				string tmp = list[int(list.size()) - l];
				cout << tmp;
				list.erase(list.end() - l);
				list.pb(tmp);
			} else { 
				if (isalpha(s[i])) x += s[i];
				else if (x != "") { 
					if (find(list.begin(), list.end(), x) != list.end()) list.erase(find(list.begin(), list.end(), x));
					list.pb(x);
					x = "";
				}
				cout << s[i];
				++i;
			}
		}
		if (x != "") { 
			if (find(list.begin(), list.end(), x) != list.end()) list.erase(find(list.begin(), list.end(), x));
			list.pb(x);
			x = "";
		}
		cout << "\n";
	}
	return 0;
}
