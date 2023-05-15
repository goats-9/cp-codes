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

int n;

void solve(string &s, string &t) { 
	vector<vi> ch(6);
	f(i, 0, n, 1) { 
		if (s[i] == 'a') ch[0].pb(i);
		else if (s[i] == 'b') ch[1].pb(i);
		else ch[2].pb(i);
		if (t[i] == 'a') ch[3].pb(i);
		else if (t[i] == 'b') ch[4].pb(i);
		else ch[5].pb(i);
	}
	if ((ch[0].size() != ch[3].size()) || (ch[1].size() != ch[4].size()) || (ch[2].size() != ch[5].size())) {printf("NO\n"); return;}
	int x = ch[0].size();
	int y = ch[2].size();
	int del;
	f(i, 0, x, 1) { 
		if (ch[2].size() != 0 && ch[1].size() != 0) {
			int c_idx = lower_bound(ch[2].begin(), ch[2].end(), ch[0][i]) - ch[2].begin();
			del = upper_bound(ch[1].begin(), ch[1].end(), ch[2][c_idx]) - lower_bound(ch[1].begin(), ch[1].end(), ch[0][x]) + 1;
		} else del = n - ch[0][i] - 1;
		if (ch[0][i] + del < ch[3][i]) {printf("NO\n"); return;}
	}
	f(i, 0, y, 1) { 
		if (ch[0].size() != 0 && ch[1].size() != 0) {
			int down = upper_bound(ch[0].begin(), ch[0].end(), ch[2][i]) - ch[0].begin();
			del = upper_bound(ch[1].begin(), ch[1].end(), ch[2][i]) - lower_bound(ch[1].begin(), ch[1].end(), ch[0][down]) + 1;
		} else del = ch[2][i];
		if (ch[2][i] - del > ch[5][i]) {printf("NO\n"); return;}
	}
	printf("YES\n");
}

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		scanf("%d", &n);
		string s, t;
		cin >> s >> t;
		solve(s, t);
	}
	return 0;
}
