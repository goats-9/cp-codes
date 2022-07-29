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
	stack<string> stk;
	int q;
	string s;
	cin >> q;
	f(i, 0, q, 1) { 
		cin >> s;
		if (s == "Sleep") { 
			cin >> s;
			stk.push(s);
		} else if (s == "Test") { 
			if (!stk.empty()) cout << stk.top() << "\n";
			else cout << "Not in a dream\n";
		} else { 
			if (!stk.empty()) stk.pop();
		}
	}
	return 0;
}
