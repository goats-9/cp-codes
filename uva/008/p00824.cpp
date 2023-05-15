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
#define MOD 1e9 + 7

vi dr = {-1, -1, 0, 1, 1, 1, 0, -1};
vi dc = {0, -1, -1, -1, 0, 1, 1, 1};
int surr[3][3];

bool isLand(int d) {return surr[1 + dr[d]][1 + dc[d]] == 1;}

int main() {
	int x, y, d, xi, yi, fl, del_x, del_y;
	while (cin >> x && x > 0) { 
		int chk = 1;
		cin >> y >> d;
		reset(surr, 0);
		f(i, 0, 8, 1) {
			cin >> xi >> yi >> fl;
			del_x = xi - x;
			del_y = yi - y;
			if (fl) surr[1 - del_y][1 + del_x] = 1;
		}
		f(i, d - 3, d + 4, 1) if (isLand((i + 8)%8)) {cout << (i+8)%8 << "\n"; chk = 0; break;}
		if (chk) cout << (d + 4)%8 << "\n";
	}
	return 0;
}
