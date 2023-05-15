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
	int s, d, fl;
	ll sup, sum;
    while (cin >> s >> d) {
		sup = 0LL;
		f(i, 0, (1 << 12), 1) { 
			fl = 1;
			f(j, 0, 8, 1) { 
				sum = 0LL;
				f(k, j, j + 5, 1) sum += (i & (1 << k)) ? s : -d;
				if (sum > 0) {fl = 0; break;}
			}
			if (fl) { 
				sum = 0LL;
				f(j, 0, 12, 1) sum += (i & (1 << j)) ? s : -d;
				sup = max(sup, sum);
			}
		}
		if (sup > 0) cout << sup << "\n";
		else cout << "Deficit\n";
	}
	return 0;
}
