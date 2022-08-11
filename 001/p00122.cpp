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

int main() {
	int n;
	string in, s, r;
	V<pair<string, int>> elem;
	while (cin >> in) { 
		if (in != "()") { 
			n = 0;
			s = "";
			int i = 1;
			while (in[i] != ',') { 
				n = 10*n + (in[i] - '0');
				++i;
			}
			++i;
			while (in[i] != ')') { 
				s += in[i];
				++i;
			}
			elem.pb(mp(s,n));
		} else {
			int k = elem.size(), fl = 0, dig = 0;
			sort(elem.begin(), elem.end(), [](pair<string, int> &a, pair<string, int> &b) { 
				if (a.first.size() == b.first.size()) return a.first < b.first;
				return a.first.size() < b.first.size();
			});
			if (elem[0].first != "") { 
				cout << "not complete\n";
				elem.clear();
				continue;
			}
			f(i, 1, k, 1) { 
				int sz = elem[i].first.size();
				if (sz - dig == 1) ++dig;
				else if (sz - dig > 1 || elem[i].first == elem[i - 1].first) {fl = 1; break;}
			}
			if (fl) { 
				cout << "not complete\n";
				elem.clear();
				continue;
			}
			f(i, 0, k, 1) { 
				cout << elem[i].second;
				if (i == k - 1) cout << nl;
				else cout << " ";
			}
			elem.clear();
		}
	}
	return 0;
}
