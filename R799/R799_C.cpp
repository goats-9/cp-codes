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

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		vector<string> b(8);
		vi l(8);
		f(i, 0, 8, 1) {
			cin >> b[i];
			f(j, 0, 8, 1) if (b[i][j] == '#') ++l[i];
		}
		f(i, 1, 7, 1) {
			if (l[i - 1] == 2 && l[i] == 1 && l[i + 1] == 2) {
				f(j, 0, 8, 1) {
					if (b[i][j] == '#') {cout << i + 1 << " " << j + 1 << "\n"; break;}
				}
				break;
			} 
		}
	}
	return 0;
}
