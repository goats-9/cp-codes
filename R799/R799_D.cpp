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

bool isPall(string s) { 
	if (s[0] == s[4] && s[1] == s[3]) return true;
	return false;
}

string next(string &s, int x) {
	int h = 10*(s[0] - '0') + (s[1] - '0');
	int h_d = x / 60;
	h = (h + h_d) % 24;
	int m = 10*(s[3] - '0') + (s[4] - '0');
	int m_d = x % 60;
	m += m_d;
	if (m >= 60) { 
		m %= 60;
		h = (h + 1) % 24;
	}
	s = "HH:MM";
	s[1] = h%10 + '0';
	h /= 10;
	s[0] = h + '0';
	s[4] = m%10 + '0';
	m /= 10;
	s[3] = m + '0';
	return s;
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		string s;
		int x;
		cin >> s >> x;
		vector<string> time;
		time.pb(s);
		int ctr = isPall(s) ? 1 : 0;
		while (find(time.begin(), time.end(), next(s, x)) == time.end()) { 
			time.pb(s);
			if (isPall(s)) ++ctr;
		}
		cout << ctr << "\n";
	}
	return 0;
}
