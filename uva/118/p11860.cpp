#include <bits/stdc++.h>
#include <cctype>
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
#define MOD (int)1e9 + 7

bool isAlpha(char x) { 
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int main() {
	int t;
    cin >> t;
	cin.ignore(1, '\n');
    f(tc, 1, t + 1, 1) { 
		string s;
		vector<string> loc;
		unordered_map<string, int> chk;
		int n, i, num = 0;
		while (getline(cin, s) && s != "END") { 
			n = s.size(), i = 0;
			string buf = "";
			while (i < n) { 
				if (!isAlpha(s[i])) { 
					if (buf != "") {
						if (chk.find(buf) == chk.end()) {chk[buf] = 0; ++num;}
						loc.pb(buf);
					}
					buf = "";
					++i;
				} else while (i < n && isAlpha(s[i])) { 
					buf += s[i];
					++i;
				}
			}
			if (buf != "") { 
				if (chk.find(buf) == chk.end()) { chk[buf] = 0; ++num; }
				loc.pb(buf);
			}
		}
		n = loc.size();
		cout << "Document " << tc << ": ";
		int uniq = 0, l_g = 0, r_g = 0, l = 0, r = 0, shortest = INT_MAX;
		while (r < n) { 
			if (++chk[loc[r++]] == 1) ++uniq; 
			while (uniq == num) { 
				if (--chk[loc[l++]] == 0) --uniq;
				if (r - l < shortest) shortest = r - l, r_g = r, l_g = l;
			}
		}
		cout << l_g << " " << r_g << "\n";
	}
	return 0;
}
