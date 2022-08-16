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

int cost[256];

int chr(char x) {return ((int)x + 256) % 256; }

int main() {
	int t, k, m, c;
	char ch;
	string s;
    scanf("%d", &t);
    while (t--) {
		reset(cost, 0);
		cin >> k;
		f(i, 0, k, 1) { 
			cin >> ch >> c;
			cost[chr(ch)] = c;
		}
		cin >> m;
		cin.ignore(1, '\n');
		double ans = 0;
		f(i, 0, m, 1) { 
			getline(cin, s);
			f(j, 0, s.size(), 1) ans += (double)cost[chr(s[j])]/100.0;
		}
		printf("%.2lf$\n", ans);
	}
	return 0;
}
