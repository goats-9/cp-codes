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
#define INF (int)1e9

vvi am, p;

void disp(int i, int j) { 
	if (i != j) disp(i, p[i][j]);
	printf("%c ", char(j + 'A'));
}

int main() {
	int s, e, c, q;
	char x, y;
	cin >> s >> e;
	am.assign(s, vi(s, INF));
	p.assign(s, vi(s));
	f(i, 0, s, 1) f(j, 0, s, 1) p[i][j] = i;
	f(i, 0, e, 1) { 
		cin >> x >> y >> c;
		am[x - 'A'][y - 'A'] = c;
		am[y - 'A'][x - 'A'] = c;
	}
	f(k, 0, s, 1) { 
		f(i, 0, s, 1) { 
			f(j, 0, s, 1) { 
				if (am[i][j] > am[i][k] + am[k][j]) { 
					am[i][j] = am[i][k] + am[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
	cin >> q;
	f(i, 0, q, 1) { 
		cin >> x >> y;
		disp(x - 'A', p[x - 'A'][y - 'A']);
		cout << y << nl;
	}
	return 0;
}
