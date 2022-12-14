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
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7
#define INF (int)1e9
#define N (int)1e7

int main() {
	int t, x, y;
    scanf("%d", &t);
    vi spf(N + 1); spf[2] = 2;
    f(i, 2, N + 1, 1) spf[i] = i;
    f(i, 4, N + 1, 2) spf[i] = 2;
    for (int i = 3; i*i <= N; i++) if (spf[i] == i) for (int j = i*i; j <= N; j+=i) spf[j] = i;
    while (t--) { 
        scanf("%d %d", &x, &y);
        if (gcd(x, y) > 1) {cout << 0 << nl; continue;}
        int p = y - x, mn = INF;
        if (p == 1) {cout << "-1\n"; continue;}
        while (p > 1) {
            int d = spf[p];
            mn = min(mn, d - (x%d));
            while (p%d == 0) p /= d;
        }
        cout << mn << nl;
	}
	return 0;
}