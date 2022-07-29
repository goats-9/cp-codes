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
	int p, g;
	string s;
	double x;
    while (cin >> p >> g) { 
		map<string, int> party;
		f(i, 0, p, 1) { 
			cin >> s >> x;
			party[s] = x*10;
		}
		f(i, 1, g + 1, 1) {
			cin >> s;
			int cal = party[s];
			double pred;
			while (cin >> s && (s != ">" && s != "<" && s != ">=" && s != "<=" && s != "=")) { 
				if (s == "+") { 
					cin >> s;
					cal += party[s];
				}
			}
			cin >> pred;
			int p = pred*10;
			cout << "Guess #" << i << " was ";
			if (s == "<") { 
				if (cal < p) cout << "correct.\n";
				else cout << "incorrect.\n";
			}
			if (s == "<=") {
				if (cal <= p) cout << "correct.\n";
				else cout << "incorrect.\n";
			}
			if (s == ">") { 
				if (cal > p) cout << "correct.\n";
				else cout << "incorrect.\n";
			}
			if (s == ">=") {
				if (cal >= p) cout << "correct.\n";
				else cout << "incorrect.\n";
			}
			if (s == "=") {
				if (cal == p) cout << "correct.\n";
				else cout << "incorrect.\n";
			}
		}
	}
	return 0;
}
