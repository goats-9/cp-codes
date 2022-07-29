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

vi sim;

int main() {
	int t, n, ctr;
	string s;
    scanf("%d", &t);
    f(k, 1, t + 1, 1) { 
		cin >> s;
		n = s.size(), ctr = 0;
		sim.assign(n, 1);
		f(i, 0, n, 1) { 
			if (s[i] == 'D') sim[i] = 0;
			if (s[i] == 'B') sim[i] = sim[max(i - 1, 0)] = sim[max(i - 2, 0)] = 0;
			if (s[i] == 'S') sim[i] = sim[max(i - 1, 0)] = sim[min(i + 1, n - 1)] = 0;
		}
		f(i, 0, n, 1) if (sim[i]) ++ctr;
		printf("Case %d: %d\n", k, ctr);
	}
	return 0;
}
