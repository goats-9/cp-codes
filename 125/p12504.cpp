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
#define MOD (int)1e9 + 7

int main() {
	int t;
	string s1, s2;
    scanf("%d", &t);
    while (t--) { 
		cin >> s1 >> s2;
		map<string, string> d_old, d_new; 
		int sz1 = s1.size(), sz2 = s2.size(), i = 1;
		while (i < sz1 - 1) { 
			string key = "", value = "";
			while (i < sz1 - 1 && s1[i] != ':') key += s1[i++];
			++i;
			while (i < sz1 - 1 && s1[i] != ',') value += s1[i++];
			++i;
			d_old[key] = value;
		}
		i = 1;
		while (i < sz2 - 1) { 
			string key = "", value = "";
			while (i < sz2 - 1 && s2[i] != ':') key += s2[i++];
			++i;
			while (i < sz2 - 1 && s2[i] != ',') value += s2[i++];
			++i;
			d_new[key] = value;
		}
		string buf = "+";
		int f1 = 0, f2 = 0, f3 = 0;
		for (auto it = d_new.begin(); it != d_new.end(); ++it) { 
			if (d_old.find(it->first) == d_old.end()) buf += it->first + ",", f1 = 1;
		}
		buf.pop_back();
		if (f1) cout << buf << "\n";
		buf = "-";
		for (auto it = d_old.begin(); it != d_old.end(); ++it) { 
			if (d_new.find(it->first) == d_new.end()) buf += it->first + ",", f2 = 1;
		}
		buf.pop_back();
		if (f2) cout << buf << "\n";
		buf = "*";
		for (auto it = d_old.begin(); it != d_old.end(); ++it) { 
			if (d_new.find(it->first) != d_new.end() && it->second != d_new[it->first]) buf += it->first + ",", f3 = 1;
		}
		buf.pop_back();
		if (f3) cout << buf << "\n";
		if (!f1 && !f2 && !f3) cout << "No changes\n";
		cout << "\n";
	}
	return 0;
}
