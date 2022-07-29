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

vector<char> a = {'(', '[', '{', '<', '?'};
vector<char> b = {')', ']', '}', '>', '#'};

int main() {
	string s;
    while (getline(cin, s)) { 
		stack<pair<char, int>> stk;
		int n = s.size();
		char x;
		int i = 0, idx = 1, fl = 0;
		while (i < n) {
			if (s[i] == '(' && s[min(i + 1, n - 1)] == '*') x = '?', i += 2;
			else if (s[i] == '*' && s[min(i + 1, n - 1)] == ')') x = '#', i += 2;
			else x = s[i], i += 1;
			if (find(a.begin(), a.end(), x) != a.end()) stk.push({x, idx});
			if (find(b.begin(), b.end(), x) != b.end()) {
				int chk = find(b.begin(), b.end(), x) - b.begin();
				if (!stk.empty() && stk.top().first == a[chk]) stk.pop();
				else { 
					cout << "NO " << idx << "\n";
					fl = 1;
				}
			}
			if (fl) break;
			++idx;
		}
		if (!fl) {
			if (stk.empty()) cout << "YES\n";
			else cout << "NO " << idx << "\n"; 
		}
	}
	return 0;
}
