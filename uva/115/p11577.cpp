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

vector<pii> a;

int main() {
	int t;
    cin >> t;
	cin.ignore(1, '\n');
    while (t--) { 
		a.assign(26, {0, 0});
		f(i, 0, 26, 1) a[i].second = 25 - i;
		string s;
		getline(cin, s);
		f(i, 0, s.size(), 1) if (isalpha(s[i])) a[tolower(s[i]) - 'a'].first++;
		sort(a.rbegin(), a.rend());
		int key = a[0].first;
		f(i, 0, 26, 1) { 
			if (a[i].first == key) cout << char('a' + 25 - a[i].second);
			else break;
		}
		cout << "\n";
	}
	return 0;
}
