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

int main() {
	int t, n, sh, mh, sm, mm, h, m, h1, m1;
    scanf("%d", &t);
    while (t--) { 
		cin >> n >> h >> m;
		mh = 24, mm = 60;
		vector<pii> a(n);
		f(i, 0, n, 1) {
			cin >> h1 >> m1;
			if (h1 < h || (h1 == h && m1 < m)) h1 += 24;
			sm = m1 - m;
			sh = h1 - h;
			if (sm < 0) sm += 60, sh--;
			if (sh < mh || (sh == mh && sm < mm)) mh = sh, mm = sm;
		}
		cout << mh << " " << mm << "\n";
	}
	return 0;
}
